package CarTest;

public class FuelGage
{
    private int fuelAmount;

    public FuelGage(int gallonsFuel)
    {
        fuelAmount = gallonsFuel;
    }

    public int getFuelAmount()
    {
        return fuelAmount;
    }

    public void addFuel()
    {
        fuelAmount++;
    }
    public void subtractFuel()
    {
        if(fuelAmount>0)
            fuelAmount--;
    }

}
