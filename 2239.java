import java.util.*;
import java.io.*;

class Main{
    static int[][] map;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        map= new int[9][9];

        for(int i = 0; i < 9; i ++){
            char[] line = br.readLine().toCharArray();
            for(int j = 0; j < 9; j++) map[i][j] = line[j] - '0';
        }

        solve(0,0);
    }

    static boolean solve(int row, int col){
        if(col == 9){
            row++;
            col = 0;
        }

        if(row == 9){
            printMap();
            return true;
        }

        if(map[row][col] != 0) return solve(row,col+1);

        for(int i = 1; i <= 9; i++){
            if(isValid(row,col,i)){
                map[row][col] = i;
                if(solve(row,col+1)) return true;
                map[row][col] = 0;
            }
        }

        return false;
    }

    static boolean isValid(int row,int col ,int num){
        for(int i = 0; i < 9; i++){
            if(map[row][i] == num) return false;
        }

        for(int i = 0; i < 9; i++){
            if(map[i][col] == num) return false;
        }

        int boxRow = row - row%3;
        int boxCol = col - col%3;
        for(int i = boxRow; i < boxRow+3;  i++){
            for(int j = boxCol; j < boxCol+3; j++){
                if(map[i][j] == num) return false;
            }
        }

        return true;
    }

    static void printMap(){
        for(int i = 0; i < 9;  i++){
            for(int j = 0; j < 9; j++){
                System.out.print(map[i][j]);
            }
            System.out.println();
        }
    }
}