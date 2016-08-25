var React = require('react');
var ReactDOM = require('react-dom');
var ReactRouter = require('react-router');
var ReactRouter = require('react-router');
var Router = ReactRouter.Router;
var Route = ReactRouter.Route;
var IndexRoute = ReactRouter.IndexRoute;
var hashHistory = ReactRouter.hashHistory;

import Home from '/Users/rowandempster/Documents/website-react/react/components/AboutMe/DisplayedComponents/Home.jsx';
import SideProjects from './components/Projects/DisplayedPages/SideProjects';


ReactDOM.render(
  (  <Router history={hashHistory}>
    <Route path="/" component={Home}/>
    <Route path="/side_projects" component={SideProjects}/>
  </Router>),
    document.getElementById('app'));
