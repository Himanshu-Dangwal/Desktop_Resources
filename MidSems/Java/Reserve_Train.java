import java.util.*;

// Abstract class Reservation
abstract class Reservation {
    abstract boolean reserve(int seats, int typeOfSeat);
    abstract int getAvailableSeats();
}

// Subclass ReserveBus
class ReserveBus extends Reservation {
    private int totalSeats;

    // Parameterized constructor
    public ReserveBus(int totalSeats) {
        this.totalSeats = totalSeats;
    }

    // Implementation of the reserve method for bus reservation
    @Override
    boolean reserve(int seats, int typeOfSeat) {
        if (seats <= getAvailableSeats()) {
            // Bus reservation does not consider the type of seat
            System.out.println("Booked-" + seats);
            this.totalSeats = this.totalSeats - seats;
            return true;
        } else {
            System.out.println("SEATS NOT AVAILABLE FOR BUS-" + seats);
            return false;
        }
    }

    // Implementation of the getAvailableSeats method
    @Override
    int getAvailableSeats() {
        return totalSeats;
    }
}

// Subclass ReserveTrain
class ReserveTrain extends Reservation {
    private int lowerBirthTotalSeats;
    private int middleBirthTotalSeats;
    private int upperBirthTotalSeats;

    // Parameterized constructor
    public ReserveTrain(int lowerBirthTotalSeats, int middleBirthTotalSeats, int upperBirthTotalSeats) {
        this.lowerBirthTotalSeats = lowerBirthTotalSeats;
        this.middleBirthTotalSeats = middleBirthTotalSeats;
        this.upperBirthTotalSeats = upperBirthTotalSeats;
    }

    // Implementation of the reserve method for train reservation
    @Override
    boolean reserve(int typeOfSeat,int seats) {
        int availableSeats = getAvailableSeats(typeOfSeat);

        if (seats <= availableSeats) {
            System.out.println("Booked-" + seats);
            switch (typeOfSeat) {
                case 1:
                    this.lowerBirthTotalSeats -= seats;
                    break;
                case 2:
                    this.middleBirthTotalSeats -= seats;
                    break;
                case 3:
                    this.upperBirthTotalSeats -= seats;
                    break;
                default:
                    break;
            }
            return true;
        } else {
            System.out.println("SEATS NOT AVAILABLE FOR TRAIN-" + seats);
            return false;
        }
    }

    // Implementation of the getAvailableSeats method
    @Override
    int getAvailableSeats() {
        return lowerBirthTotalSeats + middleBirthTotalSeats + upperBirthTotalSeats;
    }

    // Additional method to get available seats based on the type of seat
    private int getAvailableSeats(int typeOfSeat) {
        switch (typeOfSeat) {
            case 1:
                return lowerBirthTotalSeats;
            case 2:
                return middleBirthTotalSeats;
            case 3:
                return upperBirthTotalSeats;
            default:
                return 0;
        }
    }
}

public class Reserve_Train {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reading input values
        int reservationType = scanner.nextInt();

        if (reservationType == 1) {
            // ReserveBus case
            int totalSeats = scanner.nextInt();
            int totalBookings = scanner.nextInt();
            ReserveBus reserveBus = new ReserveBus(totalSeats);

            for (int i = 0; i < totalBookings; i++) {
                int seatsToBook = scanner.nextInt();
                reserveBus.reserve(seatsToBook, 0);
            }

            System.out.println("Remaining Seats-" + reserveBus.getAvailableSeats());
        } else if (reservationType == 2) {
            // ReserveTrain case
            int lowerSeats = scanner.nextInt();
            int middleSeats = scanner.nextInt();
            int upperSeats = scanner.nextInt();
            int totalBookings = scanner.nextInt();
            ReserveTrain reserveTrain = new ReserveTrain(lowerSeats, middleSeats, upperSeats);

            for (int i = 0; i < totalBookings; i++) {
                int typeOfSeat = scanner.nextInt();
                int seatsToBook = scanner.nextInt();
                reserveTrain.reserve(typeOfSeat,seatsToBook);
            }

            System.out.println("Remaining Seats-" + reserveTrain.getAvailableSeats());
        }

        scanner.close();
    }
}
