# 🌡️ Heat Index Calculator

**Created by: KartikeyaNainkhwal**  
**For: Hacktoberfest 2025 - Issue #164**

## 📋 Overview

This project provides **two comprehensive Heat Index Calculator implementations** in Java:
1. **GUI Calculator** - User-friendly Swing-based graphical interface
2. **Console Calculator** - Interactive command-line calculator

Both calculators use the official **Rothfusz regression equation** used by the National Weather Service to accurately calculate heat index values and provide safety warnings.

## 🌡️ What is Heat Index?

The Heat Index (HI) is a measure of how hot it feels when relative humidity is factored in with the actual air temperature. High humidity reduces the body's ability to cool itself through evaporation, making it feel hotter than the actual temperature.

## ✨ Features

### 🎨 GUI Calculator (`HeatIndexCalculator.java`)

- **Professional Interface**: Clean, medical-grade styling with color-coded warnings
- **Dual Temperature Units**: Support for both Fahrenheit and Celsius input
- **Real-time Validation**: Input validation with helpful error messages
- **Visual Warning System**: Color-coded danger levels with appropriate icons
- **Calculation History**: Track previous calculations with timestamps
- **Safety Recommendations**: Detailed advice based on heat index levels
- **Warning Level Cards**: Visual reference for all danger categories
- **Keyboard Support**: Enter key calculation and tab navigation

### 💻 Console Calculator (`ConsoleHeatIndexCalculator.java`)

- **Interactive Menu System**: Easy-to-navigate command interface
- **Comprehensive Warnings**: Detailed safety information and recommendations
- **Dual Unit Support**: Automatic conversion between Fahrenheit and Celsius
- **Calculation History**: Store and review up to 20 recent calculations
- **Educational Content**: Built-in warning level explanations
- **Safety Recommendations**: Specific advice for each danger level
- **Error Handling**: Robust input validation with clear error messages

## 🚨 Heat Index Warning Levels

| Heat Index | Category | Symptoms |
|------------|----------|----------|
| < 80°F (27°C) | Safe | Normal conditions |
| 80-90°F (27-32°C) | **Caution** ⚠️ | Fatigue possible with prolonged exposure |
| 90-105°F (32-41°C) | **Extreme Caution** ⚠️ | Heat exhaustion possible |
| 105-130°F (41-54°C) | **Danger** 🔴 | Heat exhaustion/cramps likely |
| > 130°F (54°C) | **Extreme Danger** 🆘 | Heat stroke highly likely |

## 🧮 Calculation Method

Uses the **Rothfusz regression equation** (same as National Weather Service):

```
HI = -42.379 + 2.04901523×T + 10.14333127×RH - 0.22475541×T×RH 
     - 6.83783×10⁻³×T² - 5.481717×10⁻²×RH² + 1.22874×10⁻³×T²×RH 
     + 8.5282×10⁻⁴×T×RH² - 1.99×10⁻⁶×T²×RH²
```

Where: T = Temperature (°F), RH = Relative Humidity (%)

**Additional adjustments** are applied for specific humidity and temperature ranges to improve accuracy.

## 🚀 Getting Started

### Prerequisites
- Java Development Kit (JDK) 8 or higher
- Java Runtime Environment for execution

### Installation & Running

#### GUI Calculator
```bash
# Compile
javac HeatIndexCalculator.java

# Run
java HeatIndexCalculator
```

#### Console Calculator  
```bash
# Compile
javac ConsoleHeatIndexCalculator.java

# Run
java ConsoleHeatIndexCalculator
```

## 📖 Usage Examples

### GUI Calculator Usage
1. **Enter Temperature**: Input value and select unit (°F or °C)
2. **Enter Humidity**: Input relative humidity percentage (0-100%)
3. **Calculate**: Click calculate button or press Enter
4. **View Results**: Heat index displays with color-coded warning level
5. **Check History**: Review previous calculations in the side panel

### Console Calculator Examples

```
Enter temperature: 95
Temperature unit (F for Fahrenheit, C for Celsius) [F]: F
Enter relative humidity (%): 60

📊 Results:
━━━━━━━━━━━
🌡️  Input Temperature: 95°F  
💧 Relative Humidity: 60%
🔥 Heat Index: 114°F

🔴 DANGER - Heat exhaustion and heat cramps likely; heat stroke possible!

💡 Recommendations:
   • Limit outdoor activities to early morning or evening
   • Take frequent breaks in shade or air conditioning  
   • Drink plenty of water
   • Watch for signs of heat exhaustion
```

## 🎯 Key Features Highlight

### Advanced Functionality
- **Accurate Calculations**: Uses official meteorological formulas
- **Input Validation**: Prevents invalid temperature/humidity combinations
- **Educational Value**: Teaches about heat safety and weather science  
- **Professional Grade**: Suitable for educational or safety applications
- **Cross-Platform**: Works on Windows, macOS, and Linux

### Safety Focus
- **Medical Accuracy**: Based on National Weather Service standards
- **Clear Warnings**: Easy-to-understand danger level communication
- **Actionable Advice**: Specific recommendations for each warning level
- **Visual Cues**: Color coding and icons for quick assessment

## 🔬 Technical Details

### Validation Rules
- Temperature must be ≥ 80°F (26.7°C) for accurate heat index calculation
- Humidity must be between 0-100%
- Automatic unit conversion between Fahrenheit and Celsius
- Special adjustments for low humidity and high humidity edge cases

### Accuracy Notes
- Most accurate for temperatures 80-110°F and humidity 40-85%
- Includes corrections for extreme humidity conditions
- Validated against National Weather Service heat index charts

## 🤝 Contributing

This project is part of Hacktoberfest 2025! Contributions welcome:
- Add more temperature conversion options (Kelvin, Rankine)
- Implement "feels like" temperature for cold weather
- Add mobile-responsive web version
- Enhance GUI with weather icons and animations
- Add data export functionality

## 📚 Educational Value

Perfect for:
- **Meteorology Students**: Learn heat index calculation methods
- **Safety Training**: Understand heat-related health risks  
- **Programming Students**: Study GUI development and scientific calculations
- **Health Professionals**: Quick heat safety assessments

## 📝 References

- National Weather Service Heat Index Documentation
- Rothfusz, L.P., 1990: The Heat Index Equation
- NOAA/NWS Heat Safety Guidelines

## 🙏 Acknowledgments

- National Weather Service for the heat index formula
- Hacktoberfest 2025 community
- Java Swing documentation and examples

---

**Stay Safe in the Heat! 🌡️🔥**

*Made with ❤️ by KartikeyaNainkhwal for Issue #164*
