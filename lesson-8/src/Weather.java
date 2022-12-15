public class Weather {
    private final Forecast forecast;
    private final String unit;
    private final float temperature;

    Weather(Forecast forecast, String unit, float temperature) {
        this.forecast = forecast;
        this.unit = unit;
        this.temperature = temperature;
    }

    public Weather forecastedWeather(String unit) {
        return new Weather(forecast, unit, forecast.todayTemperature());
    }

    @Override
    public String toString() {
        return String.valueOf(temperature) + unit;
    }
}
