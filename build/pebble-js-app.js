/******/ (function(modules) { // webpackBootstrap
/******/ 	// The module cache
/******/ 	var installedModules = {};
/******/
/******/ 	// The require function
/******/ 	function __webpack_require__(moduleId) {
/******/
/******/ 		// Check if module is in cache
/******/ 		if(installedModules[moduleId])
/******/ 			return installedModules[moduleId].exports;
/******/
/******/ 		// Create a new module (and put it into the cache)
/******/ 		var module = installedModules[moduleId] = {
/******/ 			exports: {},
/******/ 			id: moduleId,
/******/ 			loaded: false
/******/ 		};
/******/
/******/ 		// Execute the module function
/******/ 		modules[moduleId].call(module.exports, module, module.exports, __webpack_require__);
/******/
/******/ 		// Flag the module as loaded
/******/ 		module.loaded = true;
/******/
/******/ 		// Return the exports of the module
/******/ 		return module.exports;
/******/ 	}
/******/
/******/
/******/ 	// expose the modules object (__webpack_modules__)
/******/ 	__webpack_require__.m = modules;
/******/
/******/ 	// expose the module cache
/******/ 	__webpack_require__.c = installedModules;
/******/
/******/ 	// __webpack_public_path__
/******/ 	__webpack_require__.p = "";
/******/
/******/ 	// Load entry module and return exports
/******/ 	return __webpack_require__(0);
/******/ })
/************************************************************************/
/******/ ([
/* 0 */
/***/ (function(module, exports, __webpack_require__) {

	__webpack_require__(1);
	module.exports = __webpack_require__(2);


/***/ }),
/* 1 */
/***/ (function(module, exports) {

	(function(p) {
	  if (!p === undefined) {
	    console.error('Pebble object not found!?');
	    return;
	  }
	
	  // Aliases:
	  p.on = p.addEventListener;
	  p.off = p.removeEventListener;
	
	  // For Android (WebView-based) pkjs, print stacktrace for uncaught errors:
	  if (typeof window !== 'undefined' && window.addEventListener) {
	    window.addEventListener('error', function(event) {
	      if (event.error && event.error.stack) {
	        console.error('' + event.error + '\n' + event.error.stack);
	      }
	    });
	  }
	
	})(Pebble);


/***/ }),
/* 2 */
/***/ (function(module, exports) {

	Pebble.addEventListener('ready', function() {
	  console.log('PebbleKit JS ready!');
	  getWeather();
	});
	
	Pebble.addEventListener('appMessage', function(e) {
	  console.log("AppMessage received!");
	  getWeather();
	});
	
	function fetch(pos) {
	    let key = '8606f0764178c1587dce79db3b1ddba4'; 
	    let url = 'http://api.openweathermap.org/data/2.5/weather?lat=' + pos.coords.latitude + '&lon=' + pos.coords.longitude + '&appid=' + key;
	    
	    var req = new XMLHttpRequest();
	    req.open('GET', url, true);
	    req.onload = function(e) {
	        if (req.readyState == 4) {
	            //200 - HTTP OK
	            if (req.status == 200) {
	                var json = JSON.parse(req.responseText);
	
	                // Temperature in Kelvin requires adjustment
	                var temperature = Math.round(json.main.temp - 273.15);
	                var humidity = json.main.humidity;
	                var conditions = json.weather[0].main;
	
	                var dictionary = {
	                    'TEMPERATURE': temperature,
	                    'HUMIDITY': humidity,
	                    'CONDITIONS': conditions                            
	                }
	
	                Pebble.sendAppMessage(dictionary, 
	                    function(e) {
	                        console.log('Weather info sent to Pebble successfully!');
	                    },
	                    function(e) {
	                        console.log('Error sending weather info to Pebble!');
	                    }
	                );
	            }
	        }
	    }
	    req.send();
	}
	
	function locationErr(err) {
	    console.log("Error requesting location!");
	}
	
	function getWeather() {
	    navigator.geolocation.getCurrentPosition(fetch, locationErr, {timeout: 15000, maximumAge: 60000});
	}


/***/ })
/******/ ]);
//# sourceMappingURL=pebble-js-app.js.map