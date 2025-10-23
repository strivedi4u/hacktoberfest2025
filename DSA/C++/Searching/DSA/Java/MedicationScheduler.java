import java.util.*;
/**
 * MedicationScheduler (Interactive version)
 *
 * Asks user for medication schedules, then merges them into minimal alarm times.
 * Demonstrates DSA (TreeMap sorting + merging) while solving a real-life problem.
 */
public class MedicationScheduler {
    // Represents a single medication schedule entry
    public static class MedSchedule {
        public final String name;
        public final int startMinutes;   // minutes since midnight
        public final int interval;       // interval in minutes between doses
        public final int count;          // number of doses

        public MedSchedule(String name, int startMinutes, int interval, int count) {
            this.name = name;
            this.startMinutes = startMinutes;
            this.interval = interval;
            this.count = count;
        }
    }

    // Represents one alarm with list of meds
    public static class Alarm {
        public final int timeMinutes;
        public final List<String> meds;

        public Alarm(int timeMinutes, List<String> meds) {
            this.timeMinutes = timeMinutes;
            this.meds = meds;
        }

        public String timeString() {
            int hh = (timeMinutes / 60) % 24;
            int mm = timeMinutes % 60;
            return String.format("%02d:%02d", hh, mm);
        }

        @Override
        public String toString() {
            return timeString() + " -> " + meds;
        }
    }

    // Convert HH:MM to total minutes
    public static int parseHM(String hhmm) {
        String[] parts = hhmm.split(":");
        int hh = Integer.parseInt(parts[0]);
        int mm = Integer.parseInt(parts[1]);
        return hh * 60 + mm;
    }

    // Generate merged alarms
    public static List<Alarm> generateAlarms(List<MedSchedule> schedules) {
        TreeMap<Integer, List<String>> timeToMeds = new TreeMap<>();

        for (MedSchedule s : schedules) {
            for (int i = 0; i < s.count; i++) {
                int t = s.startMinutes + i * s.interval;
                int normalized = ((t % (24 * 60)) + (24 * 60)) % (24 * 60);
                timeToMeds.computeIfAbsent(normalized, k -> new ArrayList<>()).add(s.name);
            }
        }

        List<Alarm> alarms = new ArrayList<>();
        for (Map.Entry<Integer, List<String>> e : timeToMeds.entrySet()) {
            List<String> meds = e.getValue();
            Collections.sort(meds);
            alarms.add(new Alarm(e.getKey(), meds));
        }
        return alarms;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<MedSchedule> schedules = new ArrayList<>();

        System.out.println("==== Medication Scheduler ====");
        System.out.print("How many medications do you want to enter? ");
        int n = sc.nextInt();
        sc.nextLine(); // consume newline

        for (int i = 1; i <= n; i++) {
            System.out.println("\nEnter details for medication #" + i);
            System.out.print("Medication name: ");
            String name = sc.nextLine();

            System.out.print("First dose time (HH:MM): ");
            String time = sc.nextLine();

            System.out.print("Repeat interval in hours: ");
            double hours = sc.nextDouble();

            System.out.print("Number of doses: ");
            int count = sc.nextInt();
            sc.nextLine(); // consume newline

            int startMinutes = parseHM(time);
            int intervalMinutes = (int) (hours * 60);
            schedules.add(new MedSchedule(name, startMinutes, intervalMinutes, count));
        }

        System.out.println("\nGenerating optimized alarm schedule...");
        List<Alarm> alarms = generateAlarms(schedules);

        System.out.println("\n=== Final Alarm Schedule ===");
        for (Alarm a : alarms) {
            System.out.println(a);
        }

        System.out.println("\nTotal alarms: " + alarms.size());
        System.out.println("=============================");
        sc.close();
    }
}

