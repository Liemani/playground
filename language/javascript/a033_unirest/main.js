const unirest = require("unirest");

var Request = unirest('GET', 'http://192.168.0.42:3233');
 
Request
  .header({'Authorization': 'me'})
  .end(function (response) {
      console.log(response);
  })
