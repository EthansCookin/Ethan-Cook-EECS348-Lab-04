#include <stdio.h>

float celsius_to_fahrenheit(float celsius){ //converts celsius values to fahrenheit values
    return (9.0/5.0) * celsius + 32.0;
}
float fahrenheit_to_celsius(float fahrenheit){ //converts fahrenheit values to celsius values
    return (fahrenheit - 32.0) * (5.0/9.0);
}
float celsius_to_kelvin(float celsius){ //converts celsius values to kelvin values
    return celsius + 273.15;
}
float kelvin_to_celsius(float kelvin){ //converts kelvin values to celsius values
    return kelvin - 273.15;
}
float fahrenheit_to_kelvin(float fahrenheit){ //converts fahrenheit values to kelvin values by first converting to celsius, then to kelvin
    float celsius = fahrenheit_to_celsius(fahrenheit);
    return celsius_to_kelvin(celsius);
}
float kelvin_to_fahrenheit(float kelvin){ //converts kelvin values to kelvin values by first converting to celsius, then to fahrenheit
    float celsius = kelvin_to_celsius(kelvin);
    return celsius_to_fahrenheit(celsius);
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
        printf("Enter the temperature: ");
        scanf("%f", &temp);
        printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        scanf("%d", &tempScale);
    }
    printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &tempConvert);

    if (tempScale == 1){ //section to run if given temperature is in Celsius
        celsius = temp;
        if (tempConvert == 2){ //converts to Fahrenheit
            converted = celsius_to_fahrenheit(temp);
            printf("The converted temperature is: %.2f°F. \n", converted);
        }
        else if (tempConvert == 3){ //converts to Kelvin
            converted = celsius_to_kelvin(temp);
            printf("The converted temperature is: %.2fK. \n", converted);
        }
        else if (tempConvert == 1){ //runs if temperature conversion unit is also Celsius
            printf("Temperature is already in Celsius. \n");
        }
    }

    else if (tempScale == 2){ //section to run if given temperature is in Fahrenheit
        celsius = fahrenheit_to_celsius(temp); //gets the celsius temperature no matter what, as that value is used for the categorization
        if (tempConvert == 3){ //converts to Kelvin
            converted = fahrenheit_to_kelvin(temp);
            printf("The converted temperature is: %.2fK. \n", converted);
        }
        else if (tempConvert == 1){ //converts to Celsius
            converted = celsius;
            printf("The converted temperature is: %.2f°C. \n", converted);
        }  
        else if (tempConvert == 2){ //runs if temperature conversion unit is also Fahrenheit
            printf("Temperature is already in Fahrenheit. \n");
        }
    }
    else if (tempScale == 3){
        celsius = kelvin_to_celsius(temp); //gets the celsius temperature no matter what, as that value is used for the categorization
        if (tempConvert == 2){ //converts to Fahrenheit
            converted = kelvin_to_fahrenheit(temp);
            printf("The converted temperature is: %.2f°F. \n", converted);
        }
        else if (tempConvert == 1){ //converts to Celsius
            converted = celsius;
            printf("The converted temperature is: %.2f°C. \n", converted);
        } 
        else if (tempConvert == 3){ //runs if the temperature conversion unit is also Kelvin
            printf("Temperature is already in Kelvin. \n");
        }
    }

    categorize_temperature(celsius);
    system("Pause");
    return 0;
}