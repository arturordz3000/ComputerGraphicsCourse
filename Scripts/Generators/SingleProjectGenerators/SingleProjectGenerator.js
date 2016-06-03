var buildProcesses = [];

function registerBuildProcess(projectType, process) {
	buildProcesses[projectType] = process;
}

registerBuildProcess("vcxproj", require('./VisualStudio/vcx/vcxproj'));
registerBuildProcess("vcxproj_test", require('./VisualStudio/vcx/vcxproj_test'));

module.exports = { 
	generate: function (projectPath, projectInfo) {

		console.log(projectInfo.type);

		if (projectInfo.type in buildProcesses) {
			buildProcesses[projectInfo.type](projectPath, projectInfo);
		} else {
			console.log("Error: Unsupported project type");
		}

	}
}