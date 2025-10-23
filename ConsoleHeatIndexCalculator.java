/**
 * Console Heat Index Calculator
 * Created by: KartikeyaNainkhwal
 * For: Hacktoberfest 2025 - Issue #164
 */

import java.util.*;
import java.text.DecimalFormat;

public class ConsoleHeatIndexCalculator {
    
    private Scanner scanner;
    private DecimalFormat df = new DecimalFormat("#.##");
    private List<String> history = new ArrayList<>();
    
    public ConsoleHeatIndexCalculator() {
        scanner = new Scanner(System.in);
        showWelcomeMessage();
    }
    
    private void showWelcomeMessage() {
        System.out.println("╔══════════════════════════════════════════════════════════════╗");
        System.out.println("║                Heat Index Calculator                         ║");
        System.out.println("║                by KartikeyaNainkhwal                         ║");
        System.out.println("║              Hacktoberfest 2025 - Issue #164                ║");
        System.out.println("╠══════════════════════════════════════════════════════════════╣");
        System.out.println("║  The Heat Index combines air temperature and humidity        ║");
        System.out.println("║  to determine perceived temperature and heat danger levels   ║");
        System.out.println("╚══════════════════════════════════════════════════════════════╝");
        System.out.println();
        
        showWarningLevels();
    }
    
    private void showWarningLevels() {
        System.out.println("🌡️  Heat Index Warning Levels:");
        System.out.println("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
        System.out.println("🟢 < 80°F (27°C)    : Safe");
        System.out.println("🟡 80-90°F (27-32°C) : Caution - Fatigue possible");
        System.out.println("🟠 90-105°F (32-41°C): Extreme Caution - Heat exhaustion possible");
        System.out.println("🔴 105-130°F (41-54°C): Danger - Heat exhaustion/cramps likely");
        System.out.println("🆘 > 130°F (54°C)    : Extreme Danger - Heat stroke highly likely");
        System.out.println();
    }
    
    public void start() {
        boolean running = true;
        
        while (running) {
            System.out.println("📋 Options:");
            System.out.println("1. Calculate Heat Index");
            System.out.println("2. View Calculation History");
            System.out.println("3. Clear History");
            System.out.println("4. Show Warning Levels");
            System.out.println("5. Exit");
            System.out.print("\nEnter choice (1-5): ");
            
            try {
                int choice = Integer.parseInt(scanner.nextLine().trim());
                
                switch (choice) {
                    case 1:
                        calculateHeatIndex();
                        break;
                    case 2:
                        showHistory();
                        break;
                    case 3:
                        clearHistory();
                        break;
                    case 4:
                        showWarningLevels();
                        break;
                    case 5:
                        running = false;
                        System.out.println("\n👋 Thank you for using Heat Index Calculator!");
                        break;
                    default:
                        System.out.println("❌ Invalid choice. Please enter 1-5.");
                }
            } catch (NumberFormatException e) {
                System.out.println("❌ Invalid input. Please enter a number 1-5.");
            }
            
            if (running) {
                System.out.println("\nPress Enter to continue...");
                scanner.nextLine();
                System.out.println();
            }
        }
        
        scanner.close();
    }
    
    private void calculateHeatIndex() {
        System.out.println("\n🌡️  Heat Index Calculation");
        System.out.println("━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
        
        try {
            // Get temperature
            System.out.print("Enter temperature: ");
            double temperature = Double.parseDouble(scanner.nextLine().trim());
            
            // Get temperature unit
            System.out.print("Temperature unit (F for Fahrenheit, C for Celsius) [F]: ");
            String unitInput = scanner.nextLine().trim().toUpperCase();
            boolean isCelsius = unitInput.equals("C");
            String tempUnit = isCelsius ? "°C" : "°F";
            
            // Get humidity
            System.out.print("Enter relative humidity (%): ");
            double humidity = Double.parseDouble(scanner.nextLine().trim());
            
            // Validate inputs
            if (humidity < 0 || humidity > 100) {
                System.out.println("❌ Error: Humidity must be between 0 and 100 percent.");
                return;
            }
            
            // Convert to Fahrenheit if necessary and validate
            double tempF = temperature;
            if (isCelsius) {
                tempF = (temperature * 9.0 / 5.0) + 32;
                if (temperature < 26.7) { // 80°F
                    System.out.println("❌ Error: Heat index calculation requires temperature ≥ 80°F (26.7°C).");
                    return;
                }
            } else {
                if (temperature < 80) {
                    System.out.println("❌ Error: Heat index calculation requires temperature ≥ 80°F (26.7°C).");
                    return;
                }
            }
            
            // Calculate heat index
            double heatIndex = calculateHeatIndexValue(tempF, humidity);
            
            // Display results
            displayResults(temperature, humidity, heatIndex, isCelsius);
            
            // Add to history
            addToHistory(temperature, humidity, heatIndex, isCelsius);
            
        } catch (NumberFormatException e) {
            System.out.println("❌ Error: Please enter valid numeric values.");
        } catch (Exception e) {
            System.out.println("❌ Error: " + e.getMessage());
        }
    }
    
    private double calculateHeatIndexValue(double tempF, double humidity) {
        double T = tempF;
        double RH = humidity;
        
        if (T < 80) {
            return T;
        }
        
        // Rothfusz regression equation for heat index
        double HI = -42.379 + 
                   2.04901523 * T + 
                   10.14333127 * RH - 
                   0.22475541 * T * RH - 
                   6.83783e-3 * T * T - 
                   5.481717e-2 * RH * RH + 
                   1.22874e-3 * T * T * RH + 
                   8.5282e-4 * T * RH * RH - 
                   1.99e-6 * T * T * RH * RH;
        
        // Adjustments for specific conditions
        if (RH < 13 && T >= 80 && T <= 112) {
            double adjustment = ((13 - RH) / 4) * Math.sqrt((17 - Math.abs(T - 95)) / 17);
            HI -= adjustment;
        } else if (RH > 85 && T >= 80 && T <= 87) {
            double adjustment = ((RH - 85) / 10) * ((87 - T) / 5);
            HI += adjustment;
        }
        
        return HI;
    }
    
    private void displayResults(double temp, double humidity, double heatIndex, boolean isCelsius) {
        System.out.println("\n📊 Results:");
        System.out.println("━━━━━━━━━━━");
        
        String tempUnit = isCelsius ? "°C" : "°F";
        System.out.println("🌡️  Input Temperature: " + df.format(temp) + tempUnit);
        System.out.println("💧 Relative Humidity: " + df.format(humidity) + "%");
        
        // Display heat index in both units
        System.out.println("🔥 Heat Index: " + df.format(heatIndex) + "°F");
        if (isCelsius) {
            double heatIndexC = (heatIndex - 32) * 5.0 / 9.0;
            System.out.println("            " + df.format(heatIndexC) + "°C");
        }
        
        // Show warning level
        String warning = getWarningLevel(heatIndex);
        System.out.println("\n" + warning);
        
        // Show recommendations
        showRecommendations(heatIndex);
    }
    
    private String getWarningLevel(double heatIndexF) {
        if (heatIndexF >= 130) {
            return "🆘 EXTREME DANGER - Heat stroke highly likely with continued exposure!";
        } else if (heatIndexF >= 105) {
            return "🔴 DANGER - Heat exhaustion and heat cramps likely; heat stroke possible!";
        } else if (heatIndexF >= 90) {
            return "🟠 EXTREME CAUTION - Heat exhaustion and heat cramps possible!";
        } else if (heatIndexF >= 80) {
            return "🟡 CAUTION - Fatigue possible with prolonged exposure and physical activity!";
        } else {
            return "🟢 SAFE - Normal outdoor activities can be performed safely.";
        }
    }
    
    private void showRecommendations(double heatIndexF) {
        System.out.println("\n💡 Recommendations:");
        
        if (heatIndexF >= 130) {
            System.out.println("   • Avoid all outdoor activities");
            System.out.println("   • Stay in air-conditioned areas");
            System.out.println("   • Seek immediate medical attention if experiencing heat illness symptoms");
        } else if (heatIndexF >= 105) {
            System.out.println("   • Limit outdoor activities to early morning or evening");
            System.out.println("   • Take frequent breaks in shade or air conditioning");
            System.out.println("   • Drink plenty of water");
            System.out.println("   • Watch for signs of heat exhaustion");
        } else if (heatIndexF >= 90) {
            System.out.println("   • Take frequent water breaks");
            System.out.println("   • Limit strenuous outdoor activities");
            System.out.println("   • Wear light-colored, loose-fitting clothing");
            System.out.println("   • Stay in shade when possible");
        } else if (heatIndexF >= 80) {
            System.out.println("   • Stay hydrated during outdoor activities");
            System.out.println("   • Take occasional breaks");
            System.out.println("   • Monitor for fatigue");
        } else {
            System.out.println("   • Normal precautions for outdoor activities");
            System.out.println("   • Stay hydrated as usual");
        }
    }
    
    private void addToHistory(double temp, double humidity, double heatIndex, boolean isCelsius) {
        String tempUnit = isCelsius ? "°C" : "°F";
        String entry = String.format("%s %s, %s%% RH → Heat Index: %s°F", 
            df.format(temp), tempUnit, 
            df.format(humidity), 
            df.format(heatIndex));
        
        if (isCelsius) {
            double heatIndexC = (heatIndex - 32) * 5.0 / 9.0;
            entry += String.format(" (%s°C)", df.format(heatIndexC));
        }
        
        history.add(entry);
        
        // Keep only last 20 calculations
        if (history.size() > 20) {
            history.remove(0);
        }
    }
    
    private void showHistory() {
        System.out.println("\n📜 Calculation History:");
        System.out.println("━━━━━━━━━━━━━━━━━━━━━━━");
        
        if (history.isEmpty()) {
            System.out.println("No calculations performed yet.");
        } else {
            for (int i = 0; i < history.size(); i++) {
                System.out.println((i + 1) + ". " + history.get(i));
            }
        }
    }
    
    private void clearHistory() {
        history.clear();
        System.out.println("✅ History cleared successfully.");
    }
    
    public static void main(String[] args) {
        ConsoleHeatIndexCalculator calculator = new ConsoleHeatIndexCalculator();
        calculator.start();
    }
}
