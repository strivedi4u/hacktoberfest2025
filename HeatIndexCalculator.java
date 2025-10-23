/**
 * Heat Index Calculator
 * Created by: KartikeyaNainkhwal  
 * For: Hacktoberfest 2025 - Issue #164
 */

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.*;
import java.awt.event.*;
import java.text.DecimalFormat;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class HeatIndexCalculator extends JFrame implements ActionListener {
    
    private JTextField temperatureField;
    private JTextField humidityField;
    private JLabel resultLabel;
    private JLabel warningLabel;
    private JComboBox<String> tempUnitCombo;
    private JButton calculateButton;
    private JButton clearButton;
    private JTextArea historyArea;
    private DecimalFormat df = new DecimalFormat("#.##");
    
    private final Color BACKGROUND_COLOR = new Color(245, 250, 255);
    private final Color PANEL_COLOR = new Color(255, 255, 255);
    private final Color BUTTON_COLOR = new Color(52, 152, 219);
    private final Color BUTTON_HOVER = new Color(41, 128, 185);
    private final Color TEXT_COLOR = new Color(44, 62, 80);
    private final Color WARNING_COLOR = new Color(231, 76, 60);
    private final Color SAFE_COLOR = new Color(46, 204, 113);
    private final Color INPUT_BORDER = new Color(189, 195, 199);
    private final Color INPUT_FOCUS = new Color(52, 152, 219);
    
    public HeatIndexCalculator() {
        initializeGUI();
    }
    
    private void initializeGUI() {
        setTitle("Heat Index Calculator - by KartikeyaNainkhwal");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());
        getContentPane().setBackground(BACKGROUND_COLOR);
        
        createMainPanel();
        createHistoryPanel();
        createInfoPanel();
        
        pack();
        setLocationRelativeTo(null);
        setResizable(true);
    }
    
    private void createMainPanel() {
        JPanel mainPanel = new JPanel(new GridBagLayout());
        mainPanel.setBackground(PANEL_COLOR);
        
        // Create a beautiful title border
        mainPanel.setBorder(BorderFactory.createCompoundBorder(
            BorderFactory.createTitledBorder(
                BorderFactory.createLineBorder(INPUT_BORDER, 2),
                "🌡️ Heat Index Calculator",
                0, 0,
                new Font("Arial", Font.BOLD, 16),
                TEXT_COLOR
            ),
            new EmptyBorder(25, 25, 25, 25)
        ));
        
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(15, 15, 15, 15);
        
        // Temperature section
        gbc.gridx = 0; gbc.gridy = 0;
        gbc.anchor = GridBagConstraints.WEST;
        JLabel tempLabel = new JLabel("🌡️ Temperature:");
        tempLabel.setFont(new Font("Arial", Font.BOLD, 14));
        tempLabel.setForeground(TEXT_COLOR);
        mainPanel.add(tempLabel, gbc);
        
        gbc.gridx = 1;
        gbc.fill = GridBagConstraints.HORIZONTAL;
        temperatureField = createStyledTextField("Enter temperature (e.g., 85)", 12);
        mainPanel.add(temperatureField, gbc);
        
        gbc.gridx = 2;
        gbc.fill = GridBagConstraints.NONE;
        tempUnitCombo = createStyledComboBox(new String[]{"°F (Fahrenheit)", "°C (Celsius)"});
        tempUnitCombo.setSelectedIndex(0);
        mainPanel.add(tempUnitCombo, gbc);
        
        // Humidity section
        gbc.gridx = 0; gbc.gridy = 1;
        gbc.anchor = GridBagConstraints.WEST;
        JLabel humidityLabel = new JLabel("💧 Relative Humidity:");
        humidityLabel.setFont(new Font("Arial", Font.BOLD, 14));
        humidityLabel.setForeground(TEXT_COLOR);
        mainPanel.add(humidityLabel, gbc);
        
        gbc.gridx = 1;
        gbc.fill = GridBagConstraints.HORIZONTAL;
        humidityField = createStyledTextField("Enter humidity % (0-100)", 12);
        mainPanel.add(humidityField, gbc);
        
        gbc.gridx = 2;
        gbc.fill = GridBagConstraints.NONE;
        JLabel percentLabel = new JLabel("% RH");
        percentLabel.setFont(new Font("Arial", Font.BOLD, 14));
        percentLabel.setForeground(TEXT_COLOR);
        mainPanel.add(percentLabel, gbc);
        
        // Button panel
        gbc.gridx = 0; gbc.gridy = 2;
        gbc.gridwidth = 3;
        gbc.fill = GridBagConstraints.HORIZONTAL;
        JPanel buttonPanel = new JPanel(new FlowLayout(FlowLayout.CENTER, 20, 10));
        buttonPanel.setBackground(PANEL_COLOR);
        
        calculateButton = createStyledButton("🧮 Calculate Heat Index", BUTTON_COLOR);
        clearButton = createStyledButton("🗑️ Clear All", new Color(149, 165, 166));
        
        buttonPanel.add(calculateButton);
        buttonPanel.add(clearButton);
        mainPanel.add(buttonPanel, gbc);
        
        // Result display
        gbc.gridx = 0; gbc.gridy = 3;
        gbc.gridwidth = 3;
        gbc.fill = GridBagConstraints.HORIZONTAL;
        
        resultLabel = new JLabel("📊 Enter temperature and humidity values above", JLabel.CENTER);
        resultLabel.setFont(new Font("Arial", Font.BOLD, 18));
        resultLabel.setForeground(TEXT_COLOR);
        resultLabel.setOpaque(true);
        resultLabel.setBackground(new Color(236, 240, 241));
        resultLabel.setBorder(BorderFactory.createCompoundBorder(
            BorderFactory.createLineBorder(INPUT_BORDER, 2, true),
            new EmptyBorder(20, 15, 20, 15)
        ));
        mainPanel.add(resultLabel, gbc);
        
        // Warning label
        gbc.gridy = 4;
        warningLabel = new JLabel("", JLabel.CENTER);
        warningLabel.setFont(new Font("Arial", Font.BOLD, 16));
        warningLabel.setBorder(new EmptyBorder(10, 10, 10, 10));
        mainPanel.add(warningLabel, gbc);
        
        add(mainPanel, BorderLayout.CENTER);
        
        // Add Enter key listener
        temperatureField.addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                if (e.getKeyCode() == KeyEvent.VK_ENTER) {
                    calculateHeatIndex();
                }
            }
        });
        
        humidityField.addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                if (e.getKeyCode() == KeyEvent.VK_ENTER) {
                    calculateHeatIndex();
                }
            }
        });
    }
    
    private void createHistoryPanel() {
        JPanel historyPanel = new JPanel(new BorderLayout());
        historyPanel.setBorder(BorderFactory.createTitledBorder(
            BorderFactory.createLineBorder(INPUT_BORDER, 2),
            "📜 Calculation History",
            0, 0,
            new Font("Arial", Font.BOLD, 14),
            TEXT_COLOR
        ));
        historyPanel.setPreferredSize(new Dimension(350, 200));
        historyPanel.setBackground(PANEL_COLOR);
        
        historyArea = new JTextArea(10, 25);
        historyArea.setEditable(false);
        historyArea.setFont(new Font("Consolas", Font.PLAIN, 12));
        historyArea.setBackground(new Color(248, 249, 250));
        historyArea.setBorder(new EmptyBorder(10, 10, 10, 10));
        historyArea.setLineWrap(true);
        historyArea.setWrapStyleWord(true);
        
        JScrollPane scrollPane = new JScrollPane(historyArea);
        scrollPane.setBorder(BorderFactory.createLineBorder(INPUT_BORDER, 1));
        scrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED);
        historyPanel.add(scrollPane, BorderLayout.CENTER);
        
        JPanel buttonPanel = new JPanel(new FlowLayout());
        buttonPanel.setBackground(PANEL_COLOR);
        
        JButton clearHistoryBtn = createStyledButton("🗑️ Clear History", new Color(231, 76, 60));
        clearHistoryBtn.addActionListener(e -> {
            historyArea.setText("");
            historyArea.append("📝 History cleared\n");
        });
        buttonPanel.add(clearHistoryBtn);
        
        historyPanel.add(buttonPanel, BorderLayout.SOUTH);
        add(historyPanel, BorderLayout.EAST);
    }
    
    private void createInfoPanel() {
        JPanel infoPanel = new JPanel(new GridLayout(1, 4, 10, 10));
        infoPanel.setBorder(new EmptyBorder(10, 10, 10, 10));
        infoPanel.setBackground(BACKGROUND_COLOR);
        
        infoPanel.add(createInfoCard("Caution", "80-90°F", new Color(255, 255, 0)));
        infoPanel.add(createInfoCard("Extreme Caution", "90-105°F", new Color(255, 165, 0)));
        infoPanel.add(createInfoCard("Danger", "105-130°F", new Color(255, 69, 0)));
        infoPanel.add(createInfoCard("Extreme Danger", "130°F+", new Color(139, 0, 0)));
        
        add(infoPanel, BorderLayout.SOUTH);
    }
    
    private JPanel createInfoCard(String title, String range, Color color) {
        JPanel card = new JPanel(new BorderLayout(5, 5));
        card.setBackground(Color.WHITE);
        card.setBorder(BorderFactory.createCompoundBorder(
            BorderFactory.createLineBorder(color, 3, true),
            new EmptyBorder(8, 8, 8, 8)
        ));
        
        // Add emoji based on danger level
        String emoji = "🟢";
        if (title.contains("Caution") && !title.contains("Extreme")) emoji = "🟡";
        else if (title.contains("Extreme Caution")) emoji = "🟠";
        else if (title.contains("Danger") && !title.contains("Extreme")) emoji = "🔴";
        else if (title.contains("Extreme Danger")) emoji = "🆘";
        
        JLabel titleLabel = new JLabel(emoji + " " + title, JLabel.CENTER);
        titleLabel.setFont(new Font("Arial", Font.BOLD, 11));
        titleLabel.setForeground(color);
        
        JLabel rangeLabel = new JLabel(range, JLabel.CENTER);
        rangeLabel.setFont(new Font("Arial", Font.PLAIN, 10));
        rangeLabel.setForeground(color.darker());
        
        card.add(titleLabel, BorderLayout.CENTER);
        card.add(rangeLabel, BorderLayout.SOUTH);
        
        return card;
    }
    
    private JTextField createStyledTextField(String placeholder, int columns) {
        JTextField field = new JTextField(columns);
        field.setFont(new Font("Arial", Font.PLAIN, 16));
        field.setBorder(BorderFactory.createCompoundBorder(
            BorderFactory.createLineBorder(INPUT_BORDER, 2, true),
            new EmptyBorder(8, 12, 8, 12)
        ));
        
        // Add placeholder text
        field.setText(placeholder);
        field.setForeground(Color.GRAY);
        
        field.addFocusListener(new FocusListener() {
            @Override
            public void focusGained(FocusEvent e) {
                if (field.getText().equals(placeholder)) {
                    field.setText("");
                    field.setForeground(TEXT_COLOR);
                }
                field.setBorder(BorderFactory.createCompoundBorder(
                    BorderFactory.createLineBorder(INPUT_FOCUS, 2, true),
                    new EmptyBorder(8, 12, 8, 12)
                ));
            }
            
            @Override
            public void focusLost(FocusEvent e) {
                if (field.getText().isEmpty()) {
                    field.setText(placeholder);
                    field.setForeground(Color.GRAY);
                }
                field.setBorder(BorderFactory.createCompoundBorder(
                    BorderFactory.createLineBorder(INPUT_BORDER, 2, true),
                    new EmptyBorder(8, 12, 8, 12)
                ));
            }
        });
        
        return field;
    }
    
    private JComboBox<String> createStyledComboBox(String[] items) {
        JComboBox<String> combo = new JComboBox<>(items);
        combo.setFont(new Font("Arial", Font.PLAIN, 14));
        combo.setBorder(BorderFactory.createCompoundBorder(
            BorderFactory.createLineBorder(INPUT_BORDER, 2, true),
            new EmptyBorder(5, 8, 5, 8)
        ));
        combo.setBackground(Color.WHITE);
        return combo;
    }
    
    private JButton createStyledButton(String text, Color bgColor) {
        JButton button = new JButton(text);
        button.setFont(new Font("Arial", Font.BOLD, 14));
        button.setBackground(bgColor);
        button.setForeground(Color.WHITE);
        button.setFocusPainted(false);
        button.setBorder(BorderFactory.createCompoundBorder(
            BorderFactory.createLineBorder(bgColor.darker(), 1, true),
            new EmptyBorder(12, 20, 12, 20)
        ));
        button.addActionListener(this);
        
        Color originalColor = bgColor;
        button.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseEntered(MouseEvent e) {
                button.setBackground(originalColor.brighter());
                button.setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR));
            }
            
            @Override
            public void mouseExited(MouseEvent e) {
                button.setBackground(originalColor);
                button.setCursor(Cursor.getDefaultCursor());
            }
        });
        
        return button;
    }
    
    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == calculateButton) {
            calculateHeatIndex();
        } else if (e.getSource() == clearButton) {
            clearFields();
        }
    }
    
    private void calculateHeatIndex() {
        try {
            String tempText = temperatureField.getText().trim();
            String humidityText = humidityField.getText().trim();
            
            // Check for placeholder text
            if (tempText.isEmpty() || tempText.contains("Enter temperature") || 
                humidityText.isEmpty() || humidityText.contains("Enter humidity")) {
                showError("Please enter both temperature and humidity values.");
                temperatureField.requestFocus();
                return;
            }
            
            double temperature = Double.parseDouble(tempText);
            double humidity = Double.parseDouble(humidityText);
            
            // Validate inputs
            if (humidity < 0 || humidity > 100) {
                showError("Humidity must be between 0 and 100 percent.");
                return;
            }
            
            // Convert Celsius to Fahrenheit if needed
            boolean isCelsius = tempUnitCombo.getSelectedIndex() == 1;
            double tempF = temperature;
            if (isCelsius) {
                tempF = (temperature * 9.0 / 5.0) + 32;
                if (temperature < 26.7) { // 80°F
                    showError("Heat index calculation requires temperature ≥ 80°F (26.7°C).");
                    return;
                }
            } else {
                if (temperature < 80) {
                    showError("Heat index calculation requires temperature ≥ 80°F (26.7°C).");
                    return;
                }
            }
            
            // Calculate heat index using Rothfusz equation
            double heatIndex = calculateHeatIndexValue(tempF, humidity);
            
            // Display results
            displayResults(temperature, humidity, heatIndex, isCelsius);
            
            // Add to history
            addToHistory(temperature, humidity, heatIndex, isCelsius);
            
        } catch (NumberFormatException ex) {
            showError("Please enter valid numeric values.");
        } catch (Exception ex) {
            showError("An error occurred: " + ex.getMessage());
        }
    }
    
    private double calculateHeatIndexValue(double tempF, double humidity) {
        // Rothfusz regression equation for heat index
        double T = tempF;
        double RH = humidity;
        
        // Simple approximation for temperatures close to 80°F
        if (T < 80) {
            return T; // Just return the temperature
        }
        
        // Full Rothfusz equation
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
        String tempUnit = isCelsius ? "°C" : "°F";
        String hiUnit = "°F";
        
        // Convert heat index to Celsius if needed
        double displayHI = heatIndex;
        if (isCelsius) {
            displayHI = (heatIndex - 32) * 5.0 / 9.0;
            hiUnit = "°C";
        }
        
        String result = String.format("🔥 Heat Index: %s %s | Input: %s%s, %s%% RH", 
            df.format(displayHI), hiUnit, df.format(temp), tempUnit, df.format(humidity));
        resultLabel.setText(result);
        resultLabel.setForeground(Color.WHITE);
        
        // Determine warning level and color
        String warning = getWarningLevel(heatIndex);
        warningLabel.setText(warning);
        
        // Set result background color based on danger level
        if (warning.contains("Extreme Danger")) {
            resultLabel.setBackground(new Color(139, 0, 0));
            warningLabel.setForeground(new Color(139, 0, 0));
        } else if (warning.contains("Danger")) {
            resultLabel.setBackground(new Color(231, 76, 60));
            warningLabel.setForeground(new Color(192, 57, 43));
        } else if (warning.contains("Extreme Caution")) {
            resultLabel.setBackground(new Color(243, 156, 18));
            warningLabel.setForeground(new Color(230, 126, 34));
        } else if (warning.contains("Caution")) {
            resultLabel.setBackground(new Color(241, 196, 15));
            warningLabel.setForeground(new Color(183, 149, 11));
        } else {
            resultLabel.setBackground(SAFE_COLOR);
            warningLabel.setForeground(SAFE_COLOR);
        }
    }
    
    private String getWarningLevel(double heatIndexF) {
        if (heatIndexF >= 130) {
            return "⚠️ EXTREME DANGER - Heat stroke highly likely!";
        } else if (heatIndexF >= 105) {
            return "⚠️ DANGER - Heat exhaustion and cramps likely!";
        } else if (heatIndexF >= 90) {
            return "⚠️ EXTREME CAUTION - Heat exhaustion possible!";
        } else if (heatIndexF >= 80) {
            return "⚠️ CAUTION - Fatigue possible with activity!";
        } else {
            return "✅ Safe conditions";
        }
    }
    
    private void addToHistory(double temp, double humidity, double heatIndex, boolean isCelsius) {
        String tempUnit = isCelsius ? "°C" : "°F";
        String hiUnit = "°F";
        double displayHI = heatIndex;
        
        if (isCelsius) {
            displayHI = (heatIndex - 32) * 5.0 / 9.0;
            hiUnit = "°C";
        }
        
        // Add timestamp and emoji based on danger level
        String timestamp = LocalDateTime.now().format(DateTimeFormatter.ofPattern("HH:mm"));
        String emoji = "🟢";
        if (heatIndex >= 130) emoji = "🆘";
        else if (heatIndex >= 105) emoji = "🔴";
        else if (heatIndex >= 90) emoji = "🟠";
        else if (heatIndex >= 80) emoji = "🟡";
        
        String entry = String.format("[%s] %s %s%s, %s%% → %s%s %s\n", 
            timestamp, emoji, df.format(temp), tempUnit, 
            df.format(humidity), df.format(displayHI), hiUnit,
            getShortWarning(heatIndex));
        
        historyArea.append(entry);
        historyArea.setCaretPosition(historyArea.getDocument().getLength());
    }
    
    private String getShortWarning(double heatIndexF) {
        if (heatIndexF >= 130) return "(EXTREME)";
        else if (heatIndexF >= 105) return "(DANGER)";
        else if (heatIndexF >= 90) return "(CAUTION+)";
        else if (heatIndexF >= 80) return "(CAUTION)";
        else return "(SAFE)";
    }
    
    private void clearFields() {
        temperatureField.setText("Enter temperature (e.g., 85)");
        temperatureField.setForeground(Color.GRAY);
        humidityField.setText("Enter humidity % (0-100)");
        humidityField.setForeground(Color.GRAY);
        resultLabel.setText("📊 Enter temperature and humidity values above");
        resultLabel.setForeground(TEXT_COLOR);
        resultLabel.setBackground(new Color(236, 240, 241));
        warningLabel.setText("");
        temperatureField.requestFocus();
    }
    
    private void showError(String message) {
        resultLabel.setText("Error: " + message);
        resultLabel.setForeground(WARNING_COLOR);
        warningLabel.setText("");
    }
    
    public static void main(String[] args) {
        try {
            UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
        } catch (Exception e) {
            System.out.println("Could not set system look and feel");
        }
        
        SwingUtilities.invokeLater(() -> {
            new HeatIndexCalculator().setVisible(true);
        });
    }
}
