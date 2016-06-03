var fileSystem = require('fs');
var stringFormat = require('stringformat');
var util = require('util');
var globalConfiguration = require("../../../../GlobalConfig");

function replaceTemplateValuesWithConfigurationValues(templateXml, configuration, projectInfo) {

	var filesToCompileXml = "";

	for (var i in configuration.IncludeCppFiles) {
		filesToCompileXml += "<ClCompile Include=\"" + configuration.IncludeCppFiles[i].fileName + "\" />";
	}

	return stringFormat(templateXml.toString(), projectInfo.name, filesToCompileXml);

}

function createProjectFileOnSpecifiedPath(projectInfo, projectXml, outputPath) {
	
	var filePath = outputPath + "\\" + projectInfo.name + "." + projectInfo.type;

	console.log("Filename: " + filePath);

	if (!globalConfiguration.isDebug) {
		fileSystem.exists(filePath, function(exists) {
			if (exists) {
				console.log("Error: Project already exists...");
				return;
			}

			fileSystem.writeFile(filePath, projectXml, function(error) {
				if (error) {
					return console.log(error);
				}

				console.log("Project file created!");
			});
		});
	}

}

function copyIncludedFiles(includedFiles, targetPath) {

	for (var fileIndex in includedFiles) {
		var filePath = __dirname + "\\" +  includedFiles[fileIndex].fileDirectory + "\\" + includedFiles[fileIndex].fileName;
		var targetFilePath = targetPath + "\\" +  includedFiles[fileIndex].fileName;

		fileSystem.createReadStream(filePath).pipe(fileSystem.createWriteStream(targetFilePath));
	}

}

module.exports = function(projectPath, projectInfo) {

	var configuration = require("./" + projectInfo.configurationFile);
	configuration.ProjectName = projectInfo.name;

	var templateXml = fileSystem.readFileSync(__dirname + "/" + configuration.Template);
	var projectFileXml = replaceTemplateValuesWithConfigurationValues(templateXml, configuration, projectInfo);

	createProjectFileOnSpecifiedPath(projectInfo, projectFileXml, projectPath);
	copyIncludedFiles(configuration.IncludeCppFiles, projectPath);
}