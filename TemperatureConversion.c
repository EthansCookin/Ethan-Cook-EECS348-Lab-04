#include <stdio.h>

float celsius_to_fahrenheit(float celsius){ //converts celsius values to fahrenheit values
    float fahrenheit = (9.0/5.0) * celsius + 32.0;
    return fahrenheit;
}

float fahrenheit_to_celsius(float fahrenheit){ //converts fahrenheit values to celsius values
    float celsius = (fahrenheit - 32.0) * (5.0/9.0);
    return celsius;
}

float celsius_to_kelvin(float celsius){ //converts celsius values to kelvin values
    float kelvin = celsius + 273.15;
    return kelvin;
}

float kelvin_to_celsius(float kelvin){ //converts kelvin values to celsius values
    float celsius = kelvin - 273.15;
    return celsius;
}

float fahrenheit_to_kelvin(float fahrenheit){ //converts fahrenheit values to kelvin values by first converting to celsius, then to kelvin
    float celsius = fahrenheit_to_celsius(fahrenheit);
    float kelvin = celsius_to_kelvin(celsius);
    return kelvin;
}

float kelvin_to_fahrenheit(float kelvin){ //converts kelvin values to kelvin values by first converting to celsius, then to fahrenheit
    float celsius = kelvin_to_celsius(kelvin);
    float fahrenheit = celsius_to_fahrenheit(celsius);
    return fahrenheit;
}


void categorize_temperature(float temp){ //takes a temperature value (in celsius) and outputs the category of that temperature alongside a weather advisory
    if (temp <= 0){
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Wear a coat and beware of snow.\n");
    }
    else if (temp > 0 && temp <= 10){
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket.\n");
    }
    else if (temp > 10 && temp <= 25){
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: You should feel comfortable.\n");
    }
    else if (temp > 25 && temp <= 35){
        printf("Temperature category: Hot\n");
        printf("Weather advisory: It's t-shirt and shorts weather.\n");
    }
    else if (temp > 35){
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Avoid contact with the outside world :)\n");
    }
}

int main(){
    float temp = 0.0;
    int tempScale = 0;
    int tempConvert = 0;
    float converted = 0.0;
    float celsius = 0.0;
    printf("Enter the temperature: ");
    scanf("%f", &temp);
    printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &tempScale);
    if (tempScale == 3 && temp < 0){ //checks if a kelvin value is invalid (below 0)
        printf("Kelvin temperatures cannot go below 0\n");
        system("Pause");
        return 0;
    }
    printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &tempConvert);


    if (tempScale == 2){
        celsius = fahrenheit_to_celsius(temp);
        if (tempConvert == 3){
            converted = fahrenheit_to_kelvin(temp);
            printf("The converted temperature is: %fK. \n", converted);
        }
        else if (tempConvert == 1){
            converted = celsius;
            printf("The converted temperature is: %f°C. \n", converted);
        }  
        else if (tempConvert == 2){
            printf("Temperature is already in Fahrenheit. \n");
        }
    }
    else if (tempScale == 3){
        celsius = kelvin_to_celsius(temp);
        if (tempConvert == 2){
            converted = kelvin_to_fahrenheit(temp);
            printf("The converted temperature is: %f°F. \n", converted);
        }
        else if (tempConvert == 1){
            converted = celsius;
            printf("The converted temperature is: %f°C. \n", converted);
        } 
        else if (tempConvert == 3){
            printf("Temperature is already in Kelvin. \n");
        }
    }
    else if (tempScale == 1){
        celsius = temp;
        if (tempConvert == 2){
            converted = celsius_to_fahrenheit(temp);
            printf("The converted temperature is: %f°F. \n", converted);
        }
        else if (tempConvert == 3){
            converted = celsius_to_kelvin(temp);
            printf("The converted temperature is: %fK. \n", converted);
        }
        else if (tempConvert == 1){
            printf("Temperature is already in Celsius. \n");
        }
    }

    categorize_temperature(celsius);
    system("Pause");
    return 0;
}