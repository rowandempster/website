var express = require('express');
var app = express();
var nodemailer = require('nodemailer');
var bodyParser = require('body-parser');

app.use(bodyParser.urlencoded({ extended: false }))

app.use(bodyParser.json())


app.use(function(req, res, next) {
  res.header("Access-Control-Allow-Origin", "*");
  res.header("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
  res.setHeader('Content-Type', 'text/plain')
  res.write('you posted:\n')
  res.end(JSON.stringify(req.body, null, 2))
  next();
});


app.listen(3000, function () {
  console.log('Example app listening on port 3000!');
});


var router = express.Router();
app.post('/sayHello', handleSayHello);

function handleSayHello(req, res) {
  console.log(req.body);
  // Not the movie transporter!
  var transporter = nodemailer.createTransport({
    service: 'Gmail',
    auth: {
      user: 'rowanwebsite@gmail.com', // Your email id
      pass: 'rowan1aidan2' // Your password
    }
  });

  var text = 'Hello world from rowan';

  var mailOptions = {
    from: 'rowanwebsite@gmail.com', // sender address
    to: 'rowan.dempster@gmail.com', // list of receivers
    subject: req.body.subject, // Subject line
    // text: req.body.body //, // plaintext body
    html: req.body.body // You can choose to send an HTML body instead
  };

  transporter.sendMail(mailOptions, function(error, info){
    if(error){
      res.end('{"error" : "Failed to send email", "status" : 400}');
      console.log("we got an error!" + error);
    }else{
      res.end('{"success" : "Sent email", "status" : 200}');
      console.log('Message sent: ' + info.response);
    };
  });
}
