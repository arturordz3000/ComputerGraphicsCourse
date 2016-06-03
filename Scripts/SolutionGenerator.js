var platforms = {
	Windows: 'win32',
	OSX: 'darwin',
	Linux: 'linux'
}

var buildProcesses = [];

function registerBuildProcess(platform, process) {
	buildProcesses[platform] = process;
}

registerBuildProcess(platforms.Windows, require('./Generators/VisualStudioGenerator'));

registerBuildProcess(platforms.OSX, require('./Generators/XCodeGenerator'));

if (process.platform in buildProcesses)
	module.exports = { generate: buildProcesses[process.platform] };
else
	module.exports = { generate: function() { console.log('Unsupported platform: ' + process.platform)} };