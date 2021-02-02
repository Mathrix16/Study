//Jakub Migala - 2

import java.util.Scanner;

class Unit {

    private int amount;
    private char ch;

    public Unit(char x) {
        this.ch = x;
        this.amount = 0;
    }

    public boolean greaterEqual(Unit comp) {      //funkcja porownujaca dwa elementy kopca - zgodnie z poleceniem         
        if (this.amount > comp.amount) {
            return true;
        }
        if (this.amount == comp.amount) {
            if(this.ch<95&&comp.ch<95){
                return (this.ch<=comp.ch);
            }
            else if(this.ch<95&&comp.ch>95){
                
                return (this.ch<=comp.ch-32);
            }
            else if(this.ch>95&&comp.ch<95){
                
                return (this.ch-32<comp.ch);
            }
            else
            {
                return (this.ch<=comp.ch);
            }
        }

        return false;
    }

    public char getChar() {
        return this.ch;
    }

    public void up(int x) { //funkcja zwiekszajaca priorytet danego elementu
        this.amount += x;
    }

    public int getPrio() {
        return this.amount;
    }
}

class Heap {

    private int maxSize;
    private int curr;
    private Unit tab[];
    
    public Heap() {
        this.maxSize = 52;
        this.curr = 0;
        this.tab = new Unit[maxSize];
    }

    public void display() {
        for (int i = this.getSize() - 1; i >= 0; i--) {
            System.out.print(tab[i].getChar() + " (" + tab[i].getPrio() + ") ");
        }
        System.out.println();
    }

    public void upHeap(int k) { //PRZESIEWANIE W GORE O ZLOZONOSCI LOGARYTMICZNEJ
        int i = (k - 1) / 2;
        Unit tmp = tab[k];
        while (k > 0 && !(tab[i].greaterEqual(tmp))) {
            tab[k] = tab[i];
            k = i;
            i = (i - 1) / 2;

        }
        tab[k] = tmp;
    }

    public int get() {
        int root = tab[0].getPrio();
        curr--;
        tab[0] = tab[curr];
        downHeap(0, curr);
        return root;
    }

    public int getSize() {
        return this.curr;
    }
    public int getMax(){
        return tab[0].getPrio();
    }
    public char rootChar() {
        return tab[0].getChar();
    }

    public void downHeap(int k, int n) {    //PRZESIEWANIE W  DOL O ZLOZONOSCI  LOGARYTMICZNEJ
        int j;
        Unit tmp = tab[k];
        while (k < n / 2) {
            j = 2 * k + 1;
            if (j < n - 1 && !(tab[j].greaterEqual(tab[j + 1]))) {
                j++;
            }
            if (tmp.greaterEqual(tab[j])) {
                break;
            }
            tab[k] = tab[j];
            k = j;
        }
        tab[k] = tmp;
    }

    public void Heapsort(int n) {

        Unit supp;
        for (int k = (n - 1) / 2; k >= 0; k--) {
            downHeap(k, n);
        }
        while (n > 0) { //DRUGA FAZA SORTOWANIA
            supp = tab[0];
            tab[0] = tab[n - 1];
            tab[n - 1] = supp;    //ZAMIANA ELEMENTOW
            n--;
            downHeap(0, n);
        }
    }

    public int find(Unit x) {
        int i;
        for (i = 0; i < this.curr; i++) {
            if (tab[i].getChar() == x.getChar()) {
                return i;
            }
        }
        return -1;
    }

    public void Insert(Unit x, int value) {
        if (this.find(x) == -1) {
            tab[curr] = x;
            upHeap(curr);
            curr++;
        } else {
            tab[this.find(x)].up(value);
            upHeap(this.find(x));
        }
    }

}

public class Source {

    public static Scanner in = new Scanner(System.in);

    public static void main(String[] args) {
        Heap heap = new Heap();
        int prio[] = new int[123];
        for (int i = 0; i < 123; i++) //PRIORYTET ROWNY 1 DLA KAZDEJ Z LITER
        {
            prio[i] = 1;
        }
        int k = in.nextInt();
        char A;
        for (int i = 0; i < k; i++) { //PETLA NADAJACA PRIORYTETY INNE NIZ 1
            A = in.next().charAt(0);
            prio[A] = in.nextInt();
        }
        int n = in.nextInt();
        String command;
        while (n > 0) {
            command = in.next();
            if (command.equals("add")) {
                A = in.next().charAt(0);
                Unit x = new Unit(A);
                x.up(prio[A]);
                heap.Insert(x, prio[A]);               
            } else {
                if (heap.getSize() == 0) {
                    System.out.println("- (-)");
                } else {
                    System.out.println(heap.rootChar() + " (" + heap.get() + ")");
                }
            }
            n--;
        }
        if (heap.getSize() == 0) {
            System.out.println("- (-)");
        } else {
            while(heap.getSize()!=0){
                System.out.print(heap.rootChar() + " (" + heap.get() + ") ");
            }
        }
    }
}
