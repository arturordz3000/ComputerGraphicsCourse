var WindowsRegistry = require('../../node_modules/regedit');
var Promise = require('../../node_modules/promise');

var registryRoot = 'HKCR\\';

var supportedVisualStudioVersions = { 
	versionsNames: [],
	generators: {}
};

function registerGenerator(versionName, generatorFunction) {
	supportedVisualStudioVersions.versionsNames.push(versionName);
	supportedVisualStudioVersions.generators[versionName] = generatorFunction;
}

registerGenerator(registryRoot + 'VisualStudio.DTE.14.0', function(projects, options) {
	console.log('Selected VisualStudio.DTE.14.0');
});

registerGenerator(registryRoot + 'VisualStudio.DTE.12.0', function(projects, options) {
	console.log('Selected VisualStudio.DTE.12.0');
});

function createQueriesForInstalledVersions() {
	var  promises = [];

	for (var i = 0; i < supportedVisualStudioVersions.versionsNames.length; i++) {
		var versionName = supportedVisualStudioVersions.versionsNames[i];

		var promise = new Promise(function(resolve, reject) {
			WindowsRegistry.list(versionName, function(error, result) {
				resolve(result);
			});
		});

		promises.push(promise);
	}

	return promises;
}

function getSuitableProjectGenerator(queryResult) {
	var projectGenerator;

	for (var i in queryResult) {
		if (queryResult[i] !== undefined) {
			var versionName = supportedVisualStudioVersions.versionsNames[i];
			projectGenerator = supportedVisualStudioVersions.generators[versionName];

			break;
		}
	}

	return projectGenerator;
}

module.exports = function(projects, options) {	
	var queriesPromises = createQueriesForInstalledVersions();

	Promise.all(queriesPromises).then(function(queryResult) {
		var projectGenerator = getSuitableProjectGenerator(queryResult);
		projectGenerator(projects, options);
	});
}