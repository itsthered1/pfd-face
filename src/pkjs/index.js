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
                var windDeg = json.wind.deg;

                var dictionary = {
                    'TEMPERATURE': temperature,
                    'HUMIDITY': humidity,
                    'CONDITIONS': conditions,
                    'WIND_DIRECTION': windDeg                           
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
