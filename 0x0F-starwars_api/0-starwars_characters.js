#!/Users/user/.nvm/versions/node/v10.14.0/bin/node

const request = require('request');

const url = 'https://swapi-api.hbtn.io/api/films/';
const film = process.argv[2];

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
  const mico = [];
  try {
    for (const character in mico.characters) {
      const whom = mico.characters[character];
      const toprint = await whois(whom);
      console.log(toprint);
    }
  } catch (error) {
    console.error(error);
  }
}

request(url + film, function (error, response, body) {
  if (!error && response.statusCode === 200) {
    const mico = JSON.parse(body);
    charlist(mico);
  }
});
