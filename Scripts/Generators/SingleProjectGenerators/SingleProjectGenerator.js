var fileSystem = require('fs');
var globalConfiguration = require("../../GlobalConfig");
var util = require('util');

var buildProcesses = [];

function registerBuildProcess(projectType, process) {
	buildProcesses[projectType] = process;
}

var addToVisualStudioSolution = function(projectPath, projectInfo, typeGuid, projectGuid) {

	var solutionText = fileSystem.readFileSync("../" + globalConfiguration.mainSolution).toString();

	var insertionStartIndex = solutionText.indexOf("Global");

	var projectDefinitionText = 'Project("' + typeGuid + '") = "' + projectInfo.name + '", "' + projectInfo.name + '\\' + projectInfo.name + '.' + projectInfo.type + '", "{' + projectGuid + '}"\nEndProject\n';
	var updatedSolutionText = solutionText.slice(0, insertionStartIndex) + projectDefinitionText +solutionText.slice(insertionStartIndex) ;

	fileSystem.writeFileSync("../" + globalConfiguration.mainSolution, updatedSolutionText);
}

registerBuildProcess("vcxproj", { buildProject: require('./VisualStudio/vcx/vcxproj'), addToSolution: addToVisualStudioSolution, typeGuid:  "{8BC9CEB8-8B4A-11D0-8D11-00A0C91BC942}"});
registerBuildProcess("vcxproj_test",  { buildProject: require('./VisualStudio/vcx/vcxproj_test'), addToSolution: addToVisualStudioSolution, typeGuid:  "{8BC9CEB8-8B4A-11D0-8D11-00A0C91BC942}" });

module.exports = { 
	generate: function (projectPath, projectInfo) {

		console.log(projectInfo.type);

		if (projectInfo.type in buildProcesses) {
			var projectGuid = buildProcesses[projectInfo.type].buildProject(projectPath, projectInfo);

			return {			
				addToSolution: function() {
					var typeGuid = buildProcesses[projectInfo.type].typeGuid;
					buildProcesses[projectInfo.type].addToSolution(projectPath, projectInfo, typeGuid, projectGuid);
				}
			}

		} else {
			console.log("Error: Unsupported project type");
		}
		
	}
}