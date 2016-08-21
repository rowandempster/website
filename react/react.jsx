var React = require('react');
var ReactDOM = require('react-dom');
var ReactRouter = require('react-router');
var Router = ReactRouter.Router;
var Route = ReactRouter.Route;
import Home from './components/Home.jsx';
import HeaderNav from './components/MyHeaderNav.jsx';
import Projects from './components/Projects.jsx';


ReactDOM.render(
  (<Router>
    <Route path="/" component={Home} />
    <Route path="/test" component={HeaderNav} />
    <Route path="/projects" component={Projects} />
  </Router>),
  document.getElementById('app'));
