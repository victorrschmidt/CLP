import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class FileAnalyzer implements AutoCloseable {
    private final BufferedReader reader;
    private final String filePath;

    public FileAnalyzer(String filePath) throws IOException {
        this.reader = new BufferedReader(new FileReader("texts/" + filePath));
        this.filePath = filePath;
    }

    private void showFileInfo(int lineCount, int wordCount, int charCount) {
        System.out.println(String.format("Nome do arquivo: %s", this.filePath));
        System.out.println(String.format("Num de linhas: %d", lineCount));
        System.out.println(String.format("Num de palavras: %d", wordCount));
        System.out.println(String.format("Num de caracteres: %d\n", charCount));
    }

    public void analyzeContent() throws IOException, IllegalArgumentException {
        int lineCount = 0;
        int wordCount = 0;
        int charCount = 0;
        String line;
        while ((line = this.reader.readLine()) != null) {
            if (line.contains("#ERRO#")) {
                this.showFileInfo(lineCount, wordCount, charCount);
                throw new IllegalArgumentException();
            }
            String trimmed = line.trim();
            if (!trimmed.isEmpty()) {
                wordCount += trimmed.split("\\s+").length;
            }
            lineCount += 1;
            charCount += line.length();
        }
        this.showFileInfo(lineCount, wordCount, charCount);
    }

    @Override
    public void close() throws IOException {
        this.reader.close();
    }
}
