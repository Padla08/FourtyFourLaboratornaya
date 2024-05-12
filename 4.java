import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.function.Function;

public class Main {
    // Функция, которая реализует игру
    public static void playGame(Function<List<Boolean>, Boolean> algorithm1,
                                Function<List<Boolean>, Boolean> algorithm2) {
        Random rand = new Random();
        int rounds = rand.nextInt(101) + 100; // Генерация количества раундов от 100 до 200

        List<Boolean> algorithm1Choices = new ArrayList<>();
        List<Boolean> algorithm2Choices = new ArrayList<>();
        int algorithm1Score = 0;
        int algorithm2Score = 0;

        for (int round = 0; round < rounds; ++round) {
            boolean algorithm1Choice = algorithm1.apply(algorithm2Choices);
            boolean algorithm2Choice = algorithm2.apply(algorithm1Choices);

            algorithm1Choices.add(algorithm1Choice);
            algorithm2Choices.add(algorithm2Choice);

            if (algorithm1Choice && algorithm2Choice) {
                algorithm1Score += 24;
                algorithm2Score += 24;
            } else if (algorithm1Choice) {
                algorithm2Score += 20;
            } else if (algorithm2Choice) {
                algorithm1Score += 20;
            } else {
                algorithm1Score += 4;
                algorithm2Score += 4;
            }
        }

        System.out.println("Очки алгоритма 1: " + algorithm1Score);
        System.out.println("Очки алгоритма 2: " + algorithm2Score);
    }

    // Примеры алгоритмов
    public static boolean algorithm1(List<Boolean> enemyChoices) {
        // Алгоритм всегда соглашается
        return true;
    }

    public static boolean algorithm2(List<Boolean> enemyChoices) {
        // Алгоритм всегда предает
        return false;
    }

    public static boolean algorithm3(List<Boolean> enemyChoices) {
        // Алгоритм соглашается, если противник не предался в предыдущих раундах
        for (Boolean choice : enemyChoices) {
            if (!choice) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        // Запуск игры с каждым из алгоритмов
        for (int i = 0; i < 3; ++i) {
            System.out.println("Игра " + (i + 1) + ":");
            playGame(Main::algorithm1, Main::algorithm2);
            playGame(Main::algorithm1, Main::algorithm3);
            playGame(Main::algorithm2, Main::algorithm3);
            System.out.println();
        }
    }
}