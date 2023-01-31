package CarTest;

public class Odometer
{


    final int MAXIMUM_MILEAGE = 999999;
    private int mileage;

    public Odometer(int currentMileage)
    {
        if(currentMileage<=MAXIMUM_MILEAGE)
            mileage= currentMileage;
        else
        {
            System.out.println("Your mileage is reset to 0.");
            mileage = 0;
        }
    }
    public void increaseMileage()
    {
        mileage++;
    }
    public void lowerFuelGage(FuelGage fuelgage)
    {
        while(fuelgage.getFuelAmount()>0)
        {
            for(int i = 0;i<24;i++)
                increaseMileage();

            fuelgage.subtractFuel();

        }
        System.out.println("Final mileage is: " + mileage+"\nFinal amount of fuel is: " + fuelgage.getFuelAmount());
    }
}
