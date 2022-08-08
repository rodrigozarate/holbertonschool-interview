#!/Users/user/.nvm/versions/node/v10.14.0/bin/node

const request = require('request')

let url = 'https://swapi-api.hbtn.io/api/films/';
let film = process.argv[2];

function whois (whom) {
  return new Promise((resolve, reject) => {
    request(whom, (error, response, body) => {
      if (error) {
        reject(error);
      }
      resolve(JSON.parse(body).name);
    });
  });
}

async function charlist () {
  try {

    for(character in mico["characters"]){
      whom = mico["characters"][character];
      toprint = await whois(whom);
      console.log(toprint);
    }
  } catch (error) {
    console.error(error);
  }
}
// get the films endpoint OK

// get the character list of urls OK

// get each name from people endpoint OK

what = request(url+film, function(error, response, body){
  if (!error && response.statusCode == 200) {

        mico = JSON.parse(body);
	charlist(mico);
  }
});

// https://swapi-api.hbtn.io/api/people/1/
// print
