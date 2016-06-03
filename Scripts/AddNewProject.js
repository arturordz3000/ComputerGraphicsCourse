var fileSystem = require("fs");
var projectInfo = require("./Structures/ProjectInfo");
var projectGenerator = require("./Generators/SingleProjectGenerators/SingleProjectGenerator");
var globalConfiguration = require("./GlobalConfig");

function getProjectRoot() {
	var applicationPath = process.argv[1];
	var parentDirectoryIndex = applicationPath.indexOf("Scripts\\");

	return applicationPath.substring(0, parentDirectoryIndex);
}

projectInfo.initializeFromArguments(process.argv);

var projectRoot = getProjectRoot();
var projectPath = projectRoot + projectInfo.name;

console.log("Creating project on path " + projectPath);

if (!fileSystem.existsSync(projectPath)) {

	if (!globalConfiguration.isDebug) {
		fileSystem.mkdirSync(projectPath);
		console.log("Project directory created!");
	}

	projectGenerator.generate(projectPath, projectInfo).addToSolution();

} else {
	console.log("Warning: Project directory already exists.");
}