package CarTest;

import java.util.Scanner;

public class Car_Instrument_Simulator
{
    public static void main(String[] args)
    {
        final int MAX_GALLONS_FUEL = 15;
        var sc = new Scanner(System.in);

        System.out.println("How many gallons of fuel do you have?");
        int fuelAmount = sc.nextInt();
        while(fuelAmount>MAX_GALLONS_FUEL)
        {
            System.out.println("Your car can only hold 15 gallons of fuel, enter a new value.");
            fuelAmount = sc.nextInt();
        }

        var fuel = new FuelGage(fuelAmount);
        System.out.println("What is your cars mileage");
        int mileage = sc.nextInt();

        var odometer = new Odometer(mileage);
        odometer.lowerFuelGage(fuel);
    }
}
