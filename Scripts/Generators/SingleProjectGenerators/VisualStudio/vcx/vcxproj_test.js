var fileSystem = require('fs');
var xml2js = require('xml2js');
var xml2jsParser = new xml2js.Parser();
var xml2jsBuilder = new xml2js.Builder();
var util = require('util')

function replaceTemplateValuesWithConfigurationValues(templateJson, configuration) {

	templateJson.Project.PropertyGroup[0].RootNamespace = configuration.ProjectName;

	var includeFilesItemGroupIndex = templateJson.Project.ItemGroup.length - 1;
	templateJson.Project.ItemGroup[includeFilesItemGroupIndex].ClCompile = [];

	for (var fileIndex in configuration.IncludeCppFiles) {
		var fileToInclude = configuration.IncludeCppFiles[fileIndex].fileName;
		templateJson.Project.ItemGroup[includeFilesItemGroupIndex].ClCompile.push({Include: fileToInclude});
	}

	console.log(util.inspect(templateJson.Project.ItemGroup, false, null));

	return templateJson;

}

function createProjectFilesOnSpecifiedPath(projectXml, includeFiles, outputPath) {

}

module.exports = function(projectPath, projectInfo) {

	var configuration = require("./" + projectInfo.configurationFile);
	configuration.ProjectName = projectInfo.name;

	var templateXml = fileSystem.readFileSync(__dirname + "/" + configuration.Template);

	xml2jsParser.parseString(templateXml, function(error, result){
		var projectFileJson = replaceTemplateValuesWithConfigurationValues(result, configuration);
		var projectFileXml = xml2jsBuilder.buildObject(projectFileJson);

		createProjectFilesOnSpecifiedPath(projectFileXml, configuration.IncludeCppFiles, projectPath);
	});

}