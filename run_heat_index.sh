#!/bin/bash

# Heat Index Calculator Demo Script
# Created by: KartikeyaNainkhwal  
# For: Hacktoberfest 2025 - Issue #164

echo "🌡️🔥 HEAT INDEX CALCULATOR DEMO 🔥🌡️"
echo "========================================"
echo "Created by: KartikeyaNainkhwal"
echo "For: Hacktoberfest 2025 - Issue #164"
echo

# Check Java installation
if ! command -v java &> /dev/null; then
    echo "❌ Java is not installed. Please install Java to run the calculators."
    exit 1
fi

if ! command -v javac &> /dev/null; then
    echo "❌ Java compiler (javac) not found. Please install JDK."
    exit 1
fi

echo "✅ Java found: $(java -version 2>&1 | head -n 1)"
echo

# Compile function
compile_calculator() {
    local filename=$1
    echo "🔨 Compiling $filename..."
    
    if javac "$filename" 2>/dev/null; then
        echo "✅ $filename compiled successfully!"
        return 0
    else
        echo "❌ Failed to compile $filename"
        javac "$filename"
        return 1
    fi
}

# Menu function
show_menu() {
    echo
    echo "🌡️ Choose Heat Index Calculator:"
    echo "1. GUI Heat Index Calculator"
    echo "2. Console Heat Index Calculator"  
    echo "3. Compile Both Calculators"
    echo "4. Show Heat Index Information"
    echo "5. Run Demo Calculations"
    echo "6. Exit"
    echo
    read -p "Enter your choice (1-6): " choice
}

# Information function
show_heat_index_info() {
    echo
    echo "📚 Heat Index Information:"
    echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
    echo
    echo "🌡️ What is Heat Index?"
    echo "   The Heat Index combines air temperature and humidity to show"
    echo "   how hot it actually FEELS to the human body."
    echo
    echo "🧪 Calculation Method:"
    echo "   Uses the official Rothfusz regression equation from the"
    echo "   National Weather Service - the same formula used by meteorologists!"
    echo
    echo "🚨 Warning Levels:"
    echo "   🟢 < 80°F (27°C)     : Safe conditions"
    echo "   🟡 80-90°F (27-32°C)  : Caution - Fatigue possible"
    echo "   🟠 90-105°F (32-41°C) : Extreme Caution - Heat exhaustion possible"
    echo "   🔴 105-130°F (41-54°C): Danger - Heat stroke risk"
    echo "   🆘 > 130°F (54°C)     : Extreme Danger - Life threatening"
    echo
    echo "💡 Why It Matters:"
    echo "   • High humidity prevents sweat from evaporating"
    echo "   • Body cannot cool itself effectively"
    echo "   • Heat-related illness risk increases dramatically"
    echo
}

# Demo calculations
run_demo_calculations() {
    echo
    echo "🧮 Demo Calculations (Console Version):"
    echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
    echo
    
    if ! compile_calculator "ConsoleHeatIndexCalculator.java"; then
        return 1
    fi
    
    echo "Running sample calculations..."
    echo
    
    # Create input for demo
    cat << 'EOF' | java ConsoleHeatIndexCalculator
1
85
F
50
1
95
F
70
1
105
F
85
2
5
EOF
    
    echo
    echo "✨ Demo completed! Try the interactive version for full experience."
}

# Main loop
while true; do
    show_menu
    
    case $choice in
        1)
            echo
            echo "🎨 Starting GUI Heat Index Calculator..."
            if compile_calculator "HeatIndexCalculator.java"; then
                echo "🚀 Launching GUI Calculator..."
                java HeatIndexCalculator &
                echo "✨ GUI Calculator is running!"
                echo "📝 Close the window when done."
            fi
            ;;
        2)
            echo
            echo "💻 Starting Console Heat Index Calculator..."
            if compile_calculator "ConsoleHeatIndexCalculator.java"; then
                echo "🚀 Launching Console Calculator..."
                echo "📝 Follow the on-screen prompts"
                echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
                java ConsoleHeatIndexCalculator
            fi
            ;;
        3)
            echo
            echo "🔨 Compiling both Heat Index Calculators..."
            compile_calculator "HeatIndexCalculator.java"
            echo
            compile_calculator "ConsoleHeatIndexCalculator.java"
            echo
            echo "✅ Compilation complete!"
            ;;
        4)
            show_heat_index_info
            ;;
        5)
            run_demo_calculations
            ;;
        6)
            echo
            echo "👋 Thank you for trying the Heat Index Calculator!"
            echo "🌡️ Stay safe and stay hydrated!"
            echo "💚 Happy Hacktoberfest 2025!"
            exit 0
            ;;
        *)
            echo
            echo "❌ Invalid choice. Please enter 1-6."
            ;;
    esac
    
    echo
    read -p "Press Enter to continue..."
done
