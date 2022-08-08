#!/Users/user/.nvm/versions/node/v10.14.0/bin/node

const request = require('request')

let url = 'https://swapi-api.hbtn.io/api/films/';
let film = process.argv[2];

console.log(url+film);
try {
	what = request(url+film, function(error, response, body){
		if (!error && response.statusCode == 200) {
			
			mico = JSON.parse(body);

			for(character in mico["characters"]){
				whom = mico["characters"][character];
				who = request(whom, function(error, response, body){
					loro = JSON.parse(body);
					console.log(loro["name"]);
				});
			}
		}
	});
} catch (error) {
	console.error(error);
}
// get the films endpoint OK

// get the character list of urls OK

// get each name from people endpoint
// https://swapi-api.hbtn.io/api/people/1/
// print
