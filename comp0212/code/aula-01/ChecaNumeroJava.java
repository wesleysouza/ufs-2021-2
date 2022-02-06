import java.io.*;

public class ChecaNumeroJava{

    public static void main(String args[]) throws IOException{

        long tempoInicial = System.currentTimeMillis();

        FileInputStream stream = new FileInputStream("numeros.txt");
        InputStreamReader reader = new InputStreamReader(stream);
        BufferedReader bf = new BufferedReader(reader);
        String linha = "";

        int contador = 0;
        int numero = 10;

        while(linha != null){
            //System.out.println(linha);
            linha = bf.readLine();

            if(linha != null && linha.length() > 0){
                if(Integer.parseInt(linha) == numero){
                    contador++;
                }
            }
        }

        System.out.println("Numero de Ocorrencias: " + contador);

        long tempoFinal = System.currentTimeMillis();

        //Tempo em milisegundos
        System.out.printf("Tempo total: %.3f s%n", (tempoFinal - tempoInicial) / 1000d);

    }
}