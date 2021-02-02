//JAKUB MIGALA - 2
//SUBMIT NA BACE NUMBER 2815
import java.util.Scanner;

class Stack {     //KLASA DO TWORZENIA STOSU I OPERACJI Z NIM ZWIAZANYCH

    private int maxSize;
    private char[] array;
    private int top;

    public Stack(int size) {    //STOS CHAROW

        maxSize = size;
        array = new char[maxSize];
        top = maxSize;
    }

    public void push(char x) {
        if (!isFull()) {
            array[--top] = x;
        }
    }

    public char pop() {
        return array[top++];
    }

    public char top() {
        return array[top];
    }

    public boolean isEmpty() {
        if (top == maxSize) {
            return true;
        } else {
            return false;
        }
    }

    public boolean isFull() {
        if (top == 0) {
            return true;
        } else {
            return false;
        }

    }

}

class Stackstring {     //STOS STRINGOW

    private int maxSize;
    private String[] array;
    private int top;

    public Stackstring(int size) {

        maxSize = size;
        array = new String[maxSize];
        top = maxSize;
    }

    public void push(String x) {
        if (!isFull()) {
            array[--top] = x;
        }
    }

    public String pop() {
        if (isEmpty()) {
            return "";
        } else {
            return array[top++];
        }
    }

    public String top() {
        if (isEmpty()) {
            return "";
        } else {
            return array[top];
        }
    }

    public boolean isEmpty() {
        if (top == maxSize) {
            return true;
        } else {
            return false;
        }
    }

    public boolean isFull() {
        if (top == 0) {
            return true;
        } else {
            return false;
        }

    }

}

class Stackint {     //STOS INTOW

    private int maxSize;
    private int[] array;
    private int top;

    public Stackint(int size) {

        maxSize = size;
        array = new int[maxSize];
        top = maxSize;
    }

    public void push(int x) {
        if (!isFull()) {
            array[--top] = x;
        }
    }

    public int pop() {
        return array[top++];
    }

    public int top() {
        return array[top];
    }

    public boolean isEmpty() {
        if (top == maxSize) {
            return true;
        } else {
            return false;
        }
    }

    public boolean isFull() {
        if (top == 0) {
            return true;
        } else {
            return false;
        }

    }

}

public class Source {

    public static Scanner in = new Scanner(System.in);
    static final String leftoperators = "<>+-*/%";
    static final String rightoperators = "=^~";

    public static short ch_power(char x) //priorytet dla charow
    {
        if (x == '(') {
            return -1;
        } else if (x == '=') {
            return 0;
        } else if (x == '<' || x == '>') {
            return 1;
        } else if (x == '+' || x == '-') {
            return 2;
        } else if (x == '/' || x == '*' || x == '%') {
            return 3;
        } else if (x == '^') {
            return 4;
        } else {
            return 5;
        }

    }

    public static short prio(String x) //priorytet dla stringow
    {

        if (x.equals("=")) {
            return 1;
        } else if (x.equals("<") || x.equals(">")) {
            return 2;
        } else if (x.equals("+") || x.equals("-")) {
            return 3;
        } else if (x.equals("/") || x.equals("*") || x.equals("%")) {
            return 4;
        } else if (x.equals("^")) {
            return 5;
        } else if (x.charAt(0) >= 'a' && x.charAt(0) <= 'z') {
            return 7;
        } else if (x.equals("~")) {
            return 6;
        }
        return 0;

    }

    public static char kind(char x) {
        if (ch_power(x) == 1 || ch_power(x) == 2 || ch_power(x) == 3) {
            return 'l';
        } else {
            return 'r';
        }
    }

    public static String corrector(String input) //WERYFIKACJA POPRAWNOSCI
    {
        int balance = 0;      //LICZBA OPERANDOW-OPERATOROW
        int state = 0;        //AKTUALNY STAN
        int opener = 0;       //LICZNIK NAWIASOW OTWIERAJACYCH
        int ender = 0;        //LICZNIK NAWIASOW ZAMYKAJACYCH
        char last_bracket = 'n';
        char first_bracket = 'n';
        String support = "";
        int length = input.length();
        char ch = input.charAt(0);
        if (ch == 'I') {
            for (int i = 5; i < length; i++) {
                ch = input.charAt(i);
                if (ch == '(') {
                    if (state == 0 || state == 2) {
                        state = 0;
                    } else if (state == 1) {
                        support = "ONP: error";
                        return support;
                    }
                    support += ch;
                    opener++;
                    if (last_bracket == 'n') {
                        first_bracket = 'o';
                    }
                    last_bracket = 'o';
                } else if (ch == ')') {
                    if (state == 1) {
                        state = 1;
                    } else if (state == 0 || state == 2) {
                        support = "ONP: error";
                        return support;
                    }
                    support += ch;
                    ender++;
                    if (last_bracket == 'n') {
                        first_bracket = 'e';
                    }
                    last_bracket = 'e';
                } else if (ch >= 'a' && ch <= 'z') {
                    if (state == 0) {
                        state = 1;
                    } else if (state == 2) {
                        state = 1;
                    } else if (state == 1) {
                        support = "ONP: error";
                        return support;
                    }
                    balance++;
                    support += ch;
                } else if (ch == '~') {
                    if (state == 0) {
                        state = 2;
                    } else if (state == 2) {
                        state = 2;
                    } else if (state == 1) {
                        support = "ONP: error";
                        return support;
                    }
                    support += ch;
                } else if (ch == '+' || ch == '-' || ch == '^' || ch == '*'
                        || ch == '%' || ch == '/' || ch == '+'
                        || ch == '>' || ch == '<' || ch == '=') {
                    if (state == 1) {
                        state = 0;
                    } else if (state == 0 || state == 2) {
                        support = "ONP: error";
                        return support;
                    }

                    balance--;
                    support += ch;
                }

            }
            if (balance != 1 || last_bracket == 'o' || first_bracket == 'e' || state != 1 || opener != ender) {
                support = "ONP: error";
            } else {
                support = "INF: " + support;
            }
        } else {
            for (int i = 5; i < length; i++) {
                ch = input.charAt(i);
                if (ch >= 'a' && ch <= 'z') {
                    balance++;
                    support += ch;
                } else if (ch == '+' || ch == '-' || ch == '^' || ch == '*'
                        || ch == '%' || ch == '/' || ch == '+'
                        || ch == '>' || ch == '<' || ch == '=') {
                    balance--;
                    if (balance <= 0) {
                        support = "INF: error";
                        return support;
                    }
                    support += ch;
                } else if (ch == '~') //tylda
                {
                    support += ch;
                } else {

                }
            }
            ch = support.charAt(support.length() - 1);
            if (balance == 1 && !(ch >= 'a' && ch <= 'z')) {
                support = "ONP: " + support;
            } else {
                support = "INF: error";
            }
        }

        return support;
    }

    public static String modifier(String input)//KONWERSJA
    {
        short power = -1;
        char kind = 'n';
        String support = "";
        char ch = input.charAt(0);
        int length = input.length();

        if (ch == 'I') //INF--->ONP
        {
            Stack Stack = new Stack(length);
            for (int i = 5; i < length; i++) {
                ch = input.charAt(i);
                if (ch >= 'a' && ch <= 'z') {
                    support += ch;
                } else if (ch == '(') {
                    Stack.push(ch);
                } else if (ch == ')') {
                    while (!(Stack.isEmpty()) && Stack.top() != '(') {
                        support += Stack.pop();
                    }
                    if (!(Stack.isEmpty())) {
                        Stack.pop();
                    }
                } else if (ch == '+' || ch == '-' || ch == '^' || ch == '*'
                        || ch == '%' || ch == '/' || ch == '+'
                        || ch == '>' || ch == '<' || ch == '=' || ch == '~') {
                    power = ch_power(ch);
                    kind = kind(ch);
                    if (kind == 'l') {
                        while (!(Stack.isEmpty()) && ch_power(Stack.top()) >= power) {
                            support += Stack.pop();
                        }
                        Stack.push(ch);
                    } else {
                        while (!(Stack.isEmpty()) && ch_power(Stack.top()) > power) {
                            support += Stack.pop();
                        }
                        Stack.push(ch);
                    }

                }
            }
            while (!Stack.isEmpty()) {

                support += Stack.pop();
            }
            support = "ONP: " + support;
            return support;
        } else //ONP--->INF
        {
            Stackstring Str = new Stackstring(length);
            Stackint prios = new Stackint(length);
            String helper = "";
            for (int i = 5; i < length; i++) {
                ch = input.charAt(i);
                if (ch >= 'a' && ch <= 'z') //OPERAND
                {
                    Str.push(String.valueOf(ch));
                    prios.push(prio(String.valueOf(ch)));
                } else //OPERATOR
                {
                    helper = "";
                    if (ch != '~') {
                        if ((!Str.isEmpty() && prios.top() < prio(String.valueOf(ch)))
                                || (prios.top() == prio(String.valueOf(ch)) && leftoperators.indexOf(ch) != -1)) //lewa lacznosc
                        {
                            helper = "(" + Str.pop() + ")";
                        } else {
                            helper = Str.pop();
                        }

                        prios.pop();

                        if ((!Str.isEmpty() && prios.top() < prio(String.valueOf(ch)))
                                || (prios.top() == prio(String.valueOf(ch)) && rightoperators.indexOf(ch) != -1)) //prawa lacznosc
                        {
                            helper = "(" + Str.pop() + ")" + ch + helper;
                        } else {
                            helper = Str.pop() + ch + helper;
                        }

                        prios.pop();
                    } else //TYLDA
                    {
                        if (prios.top() < prio(String.valueOf(ch))) {
                            helper = ch + "(" + Str.pop() + ")";
                        } else {
                            helper = ch + Str.pop();
                        }

                        prios.pop();
                    }
                    Str.push(helper);
                    prios.push(prio(String.valueOf(ch)));
                }
            }
            return "INF: " + Str.pop();
        }

    }

    public static void main(String[] args) {             //MAIN       
        int z;
        z = in.nextInt(); //LICZBA ZESTAWOW
        in.nextLine();
        while (z > 0) {
            String input = in.nextLine();
            input = corrector(input);
            if (!(input.equals("INF: error") || input.equals("ONP: error"))) {
                input = modifier(input);
            }
            System.out.println(input);
            z--;
        }
    }
}

/*
TESTY
20
20 
ONP: ab*~~~~
ONP: abcd***
ONP: abcd^^=
ONP: abcd+-*
ONP: sos=*
ONP: abbba
ONP: abc*-
ONP: ab+a~a-+
ONP: a~
ONP: ab*~~~~
INF: a+b*c/d;
INF: a^c^d+k
INF: a*b*c
INF: a
INF: (k+a)/a^w-z
INF: z+k+w/(x-a*c)
INF: a + .........a+z+s
INF: z^k^(~a)
INF: a$$$$$$$DDDDD+x
INF: (a - l - z^z%3)/(b^z)

WYJSCIE :

INF: ~(~(~(~(a*b))))
INF: a*(b*(c*d))
INF: a=b^(c^d)
INF: a*(b-(c+d))
INF: s*(o=s)
INF: error
INF: a-b*c
INF: a+b+(~a-a)
INF: ~a
INF: ~(~(~(~(a*b))))
ONP: abc*d/+
ONP: acd^^k+
ONP: ab*c*
ONP: a
ONP: ka+aw^/z-
ONP: zk+wxac*-/+
ONP: aa+z+s+
ONP: zka~^^
ONP: ax+
ONP: error
*/
