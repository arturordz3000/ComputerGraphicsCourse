function validateRequiredParamters(args) {
	var name = args[2];

	if (name === undefined) {
		console.log( "Args Error: You must define a name for the new project." );
		return false;
	}

	return true;
}

function assignDefaultOrArgumentIfDefined(argument, defaultValue) {
	return argument !== undefined && argument !== "" ? argument : defaultValue;
}

var projectInfo = {
	name: "",
	type: "",
	configurationFile: "",
	initializeFromArguments: function( args ) {

		if (!validateRequiredParamters(args)) {
			return false;
		}

		this.name = args[2];
		this.type = assignDefaultOrArgumentIfDefined(args[3], "vcxproj");
		this.configurationFile = assignDefaultOrArgumentIfDefined(args[4], "config.json")

		return true;
	}
}

module.exports = projectInfo;