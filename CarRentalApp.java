import java.util.*;

// Car Class
class Car {
    private int carId;
    private String brand;
    private String model;
    private double dailyRate;
    private boolean available;

    public Car(int carId, String brand, String model, double dailyRate) {
        this.carId = carId;
        this.brand = brand;
        this.model = model;
        this.dailyRate = dailyRate;
        this.available = true;
    }

    public int getCarId() { return carId; }
    public String getBrand() { return brand; }
    public String getModel() { return model; }
    public double getDailyRate() { return dailyRate; }
    public boolean isAvailable() { return available; }

    public void rent() { available = false; }
    public void makeAvailable() { available = true; }

    @Override
    public String toString() {
        return "ID: " + carId + " | " + brand + " " + model + " | Rate: ₹" + dailyRate + "/day | " +
               (available ? "Available ✅" : "Rented ❌");
    }
}

// Rental Class
class Rental {
    private Car car;
    private String customerName;
    private int days;
    private double totalCost;

    public Rental(Car car, String customerName, int days) {
        this.car = car;
        this.customerName = customerName;
        this.days = days;
        this.totalCost = car.getDailyRate() * days;
        car.rent();
    }

    public double getTotalCost() { return totalCost; }
    public Car getCar() { return car; }
    public String getCustomerName() { return customerName; }

    @Override
    public String toString() {
        return "Customer: " + customerName + " | Car: " + car.getBrand() + " " + car.getModel() +
               " | Days: " + days + " | Cost: ₹" + totalCost;
    }
}

// Rental System Class
class CarRentalSystem {
    private List<Car> cars = new ArrayList<>();
    private List<Rental> rentals = new ArrayList<>();
    private double totalEarnings = 0.0;

    public void addCar(Car car) {
        cars.add(car);
        System.out.println("✅ Car added successfully: " + car.getBrand() + " " + car.getModel());
    }

    public void showAvailableCars() {
        System.out.println("\n🚗 Available Cars:");
        boolean found = false;
        for (Car c : cars) {
            if (c.isAvailable()) {
                System.out.println(c);
                found = true;
            }
        }
        if (!found) System.out.println("❌ No cars available right now!");
    }

    public Car findCarById(int id) {
        for (Car c : cars) {
            if (c.getCarId() == id) return c;
        }
        return null;
    }

    public void rentCar(int id, String customerName, int days) {
        Car car = findCarById(id);
        if (car == null) {
            System.out.println("❌ Car not found!");
            return;
        }
        if (!car.isAvailable()) {
            System.out.println("❌ Car is already rented!");
            return;
        }
        Rental rental = new Rental(car, customerName, days);
        rentals.add(rental);
        totalEarnings += rental.getTotalCost();
        System.out.println("🚘 Car rented successfully to " + customerName + " for ₹" + rental.getTotalCost());
    }

    public void returnCar(int id) {
        for (Rental r : rentals) {
            if (r.getCar().getCarId() == id) {
                r.getCar().makeAvailable();
                rentals.remove(r);
                System.out.println("✅ Car returned successfully: " + r.getCar().getModel());
                return;
            }
        }
        System.out.println("❌ No active rental found for this car!");
    }

    public void showRentedCars() {
        System.out.println("\n📋 Currently Rented Cars:");
        if (rentals.isEmpty()) {
            System.out.println("No cars rented right now.");
            return;
        }
        for (Rental r : rentals) System.out.println(r);
    }

    public void showTotalEarnings() {
        System.out.println("\n💵 Total Earnings: ₹" + totalEarnings);
    }
}

// Main Class
public class CarRentalApp {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        CarRentalSystem system = new CarRentalSystem();

        // Preloaded Cars
        system.addCar(new Car(1, "Maruti", "Swift", 1200));
        system.addCar(new Car(2, "Hyundai", "i20", 1500));
        system.addCar(new Car(3, "Tata", "Nexon", 1800));

        while (true) {
            System.out.println("\n===== CAR RENTAL MENU =====");
            System.out.println("1. Add Car");
            System.out.println("2. Show Available Cars");
            System.out.println("3. Rent a Car");
            System.out.println("4. Return a Car");
            System.out.println("5. Show Rented Cars");
            System.out.println("6. Show Total Earnings");
            System.out.println("7. Exit");
            System.out.print("Enter choice: ");
            int ch = sc.nextInt();
            sc.nextLine();

            switch (ch) {
                case 1:
                    System.out.print("Enter Car ID: ");
                    int id = sc.nextInt(); sc.nextLine();
                    System.out.print("Enter Brand: ");
                    String brand = sc.nextLine();
                    System.out.print("Enter Model: ");
                    String model = sc.nextLine();
                    System.out.print("Enter Rate per Day: ");
                    double rate = sc.nextDouble();
                    system.addCar(new Car(id, brand, model, rate));
                    break;
                case 2:
                    system.showAvailableCars();
                    break;
                case 3:
                    System.out.print("Enter Car ID to rent: ");
                    int rentId = sc.nextInt(); sc.nextLine();
                    System.out.print("Enter Customer Name: ");
                    String customer = sc.nextLine();
                    System.out.print("Enter No. of Days: ");
                    int days = sc.nextInt();
                    system.rentCar(rentId, customer, days);
                    break;
                case 4:
                    System.out.print("Enter Car ID to return: ");
                    system.returnCar(sc.nextInt());
                    break;
                case 5:
                    system.showRentedCars();
                    break;
                case 6:
                    system.showTotalEarnings();
                    break;
                case 7:
                    System.out.println("👋 Exiting system...");
                    sc.close();
                    return;
                default:
                    System.out.println("⚠️ Invalid choice! Try again.");
            }
        }
    }
}
