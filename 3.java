import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Main {
    private static final int NUM_BINS = 10; // Количество интервалов для критерия хи-квадрат

    // Функция для вычисления значения критерия хи-квадрат
    private static double chiSquare(List<Integer> observed, List<Integer> expected) {
        double chiSquareValue = 0.0;
        for (int i = 0; i < observed.size(); ++i) {
            if (expected.get(i) != 0) {
                chiSquareValue += Math.pow(observed.get(i) - expected.get(i), 2) / expected.get(i);
            }
        }
        return chiSquareValue;
    }

    public static void main(String[] args) {
        Random gen = new Random();

        // Размеры массивов
        int[] arraySizes = { 50, 100, 1000 };
        for (int arraySize : arraySizes) {
            List<Integer> array = new ArrayList<>(arraySize); // Динамическое выделение памяти для массива

            // Заполнение массива
            for (int i = 0; i < arraySize; ++i) {
                array.add(gen.nextInt(100) + 1);
            }

            // Вычисление наблюдаемых частот для каждого интервала
            List<Integer> observed = new ArrayList<>(NUM_BINS);
            for (int i = 0; i < NUM_BINS; ++i) {
                observed.add(0);
            }
            for (int num : array) {
                int bin = (num - 1) / (100 / NUM_BINS);
                observed.set(bin, observed.get(bin) + 1);
            }

            // Вычисление ожидаемых частот, предполагая равномерное распределение
            List<Integer> expected = new ArrayList<>(NUM_BINS);
            for (int i = 0; i < NUM_BINS; ++i) {
                expected.add(arraySize / NUM_BINS);
            }

            // Вычисление значения критерия хи-квадрат
            double chiSquareValue = chiSquare(observed, expected);

            // Вывод результатов
            System.out.println("Размер массива: " + arraySize);
            System.out.println("Значение критерия хи-квадрат: " + chiSquareValue);

            // Проведение проверки гипотезы
            double criticalValue = 16.919; // Критическое значение для 9 степеней свободы при alpha = 0.05
            if (chiSquareValue > criticalValue) {
                System.out.println("Гипотеза отвергнута: Распределение не является примерно равномерным.");
            } else {
                System.out.println("Гипотеза принята: Распределение примерно равномерное.");
            }

            // Вычисление ожидаемого и фактического среднего
            double expectedMean = 50.5; // Ожидаемое среднее для равномерного распределения от 1 до 100
            double actualMean = 0.0;

            for (int num : array) {
                actualMean += num;
            }
            actualMean /= arraySize;

            System.out.println("Ожидаемое среднее: " + expectedMean);
            System.out.println("Фактическое среднее: " + actualMean);
            System.out.println();
        }
    }
}