import java.io.IOException;
import java.io.FileNotFoundException;

public class Main {
    public static void main(String[] args) {
        for (String filePath : args) {
            try (FileAnalyzer fa = new FileAnalyzer(filePath)) {
                fa.analyzeContent();
            }
            catch (FileNotFoundException e) {
                System.out.println(String.format(
                    "ERRO. Arquivo não encontrado.\n%s\n", e.getMessage()
                ));
            }
            catch (IllegalArgumentException e) {
                System.out.println("Processamento interrompido por encontrar a string #ERRO#.\n");
            }
            catch (IOException e) {
                System.out.println(String.format(
                    "ERRO. Problema de leitura do arquivo.\n%s\n", e.getMessage()
                ));
            }
        }
    }
}
