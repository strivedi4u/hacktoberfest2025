import java.util.Scanner;

public class CalculatorHacktoberfest {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.println("=== Calculadora Hacktoberfest 2025 ===");
        System.out.print("Digite o primeiro número: ");
        double num1 = input.nextDouble();

        System.out.print("Digite o segundo número: ");
        double num2 = input.nextDouble();

        System.out.println("Escolha a operação (+, -, *, /): ");
        char operador = input.next().charAt(0);

        double resultado;

        switch (operador) {
            case '+':
                resultado = num1 + num2;
                break;
            case '-':
                resultado = num1 - num2;
                break;
            case '*':
                resultado = num1 * num2;
                break;
            case '/':
                if (num2 != 0) {
                    resultado = num1 / num2;
                } else {
                    System.out.println("Erro: divisão por zero!");
                    input.close();
                    return;
                }
                break;
            default:
                System.out.println("Operação inválida!");
                input.close();
                return;
        }

        System.out.println("Resultado: " + resultado);
        input.close();
    }
}
