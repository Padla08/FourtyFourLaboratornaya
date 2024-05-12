import java.util.ArrayList;
import java.util.List;

public class Main {

    // Declaration of function f(x) = (x - 6)^2 + ln(x)
    static double f(double x) {
        return Math.pow(x - 6, 2) + Math.log(x);
    }

    // Declaration of derivative function f(x)
    static double df(double x) {
        return 2 * (x - 6) + 1 / x;
    }

    // Declaration of function for bisection method
    static void bisectionMethod(double a, double b, double eps, List<double[]> bisection, double[] res) {
        int N = 0;
        while ((b - a) >= eps && N < 100) {
            double c = (a + b) / 2;
            bisection.add(new double[]{N, a, b, b - a});
            if (f(c) == 0) {
                break;
            } else if (f(a) * f(c) < 0) {
                b = c;
            } else {
                a = c;
            }
            N++;
            res[0] = c;
        }
    }

    // Declaration of function for Newton's method
    static void newtonMethod(double x0, double eps, List<double[]> newton, double[] res) {
        int N = 0;
        while (Math.abs(f(x0)) >= eps && N < 100) {
            double x1 = x0 - f(x0) / df(x0);
            double diff = Math.abs(x1 - x0);
            newton.add(new double[]{N, x0, x1, diff});
            if (diff < eps) {
                break;
            }
            x0 = x1;
            N++;
            res[0] = x0;
        }
    }

    public static void main(String[] args) {
        double a = 1, b = 10, eps = 0.0001; // Initial values for interval and precision
        double[] res = new double[1]; // Variable for storing the result
        List<double[]> bisection = new ArrayList<>(); // List for storing results of bisection method
        List<double[]> newton = new ArrayList<>(); // List for storing results of Newton's method

        // Solving the equation using bisection method
        bisectionMethod(a, b, eps, bisection, res);
        System.out.println("Bisection method:");
        System.out.println("N\ta\tb\tb - a");
        for (double[] i : bisection) {
            System.out.printf("%d\t%.4f\t%.4f\t%.4f\n", (int)i[0], i[1], i[2], i[3]);
        }
        System.out.println("Root: " + res[0]);

        // Solving the equation using Newton's method
        double x0 = 9; // Initial approximation
        newtonMethod(x0, eps, newton, res);
        System.out.println("Newton's method:");
        System.out.println("N\tx0\tx1\tx1 - x0");
        for (double[] i : newton) {
            System.out.printf("%d\t%.4f\t%.4f\t%.4f\n", (int)i[0], i[1], i[2], i[3]);
        }
        System.out.println("Root: " + res[0]);
    }
}