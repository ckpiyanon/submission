import java.io.IOException;
import java.io.InputStream;
import java.util.InputMismatchException;

public class grader {
    public static void main(String[] args) throws IOException {
        InputReader inputReader = new InputReader(System.in);
        int n = inputReader.readInt();
        int[] p = new int[n];
        for (int i = 0; i < n; i++) {
			p[i] = inputReader.readInt();
        }
        int[] u = new int[n];
        for (int i = 0; i < n; i++) {
            u[i] = inputReader.readInt();
        }
        int[] d = new int[n];
        for (int i = 0; i < n; i++) {
            d[i] = inputReader.readInt();
        }
        job solver = new job();
        long result = solver.scheduling_cost(p, u, d);
        System.out.println(result);
        System.out.close();
    }
}

class InputReader {
    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;

    public InputReader(InputStream stream) {
        this.stream = stream;
    }

    public int read() {
        if (numChars == -1) {
            throw new InputMismatchException();
        }
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (numChars <= 0) {
                return -1;
            }
        }
        return buf[curChar++];
    }

    public int readInt() {
        int c = eatWhite();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9') {
                throw new InputMismatchException();
            }
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    public String readString() {
        int c = eatWhite();
        StringBuilder res = new StringBuilder();
        do {
            if (Character.isValidCodePoint(c))
                res.appendCodePoint(c);
            c = read();
        } while (!isSpaceChar(c));
        return res.toString();
    }

    private int eatWhite() {
        int c = read();
        while (isSpaceChar(c)) {
            c = read();
        }
        return c;
    }

    public static boolean isSpaceChar(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }
}

