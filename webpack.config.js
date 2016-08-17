var webpack = require('webpack');
var path = require('path');

var BUILD_DIR = path.resolve(__dirname, 'react');
var APP_DIR = path.resolve(__dirname, 'react');

var config = {
  entry: APP_DIR + '/react.jsx',
  output: {
    path: BUILD_DIR,
    filename: 'bundle.js'
  },
  module : {
    loaders : [
      {
        test: /\.jsx?$/,
        include : APP_DIR,
        exclude: /node_modules/,
        loader: 'babel-loader',
        query: {presets:['es2015', 'react']}
      }
    ]
  }, 
    resolve: {
    modulesDirectories: ['node_modules', 'bower_components'],
    extensions: ['', '.js', '.jsx']
  }
};

module.exports = config;