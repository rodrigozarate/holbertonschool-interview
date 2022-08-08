#!/Users/user/.nvm/versions/node/v10.14.0/bin/node

const request = require('request')

let url = 'https://swapi-api.hbtn.io/api/films/';
let film = process.argv[2];

console.log(url+film);
try {
	request(url+film, function(error, response, body){
		if (!error && response.statusCode == 200) {
			console.log(body);
		}
	});
} catch (error) {
	console.error(error);
}
// get the films endpoint
// get the character list of urls
// get each name from people endpoint
// https://swapi-api.hbtn.io/api/people/1/
// print
