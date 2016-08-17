var React = require('react');
var ReactDOM = require('react-dom');
var ReactRouter = require('react-router');
var Router = ReactRouter.Router;
var Route = ReactRouter.Route;
import App from './components/App.jsx';
import HeaderNav from './components/MyHeaderNav.jsx';

ReactDOM.render(
  (<Router>
    <Route path="/" component={App} />
    <Route path="/test" component={HeaderNav} />
  </Router>),
  document.getElementById('app'));
