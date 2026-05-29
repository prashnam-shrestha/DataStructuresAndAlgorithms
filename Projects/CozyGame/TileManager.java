import java.awt.Color;
import java.awt.Graphics2D;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class TileManager {

    GamePanel gp;
    int mapTileNum[][];

    public TileManager(GamePanel gp) {
        this.gp = gp;
        mapTileNum = new int[gp.maxScreenCol][gp.maxScreenRow];
        loadMap("src/res/map01.txt");
    }

    public void loadMap(String filePath) {
        try {
            BufferedReader br = new BufferedReader(new FileReader(filePath));

            int col = 0;
            int row = 0;

            while (col < gp.maxScreenCol && row < gp.maxScreenRow) {
                String line = br.readLine();

                if (line == null) break;

                String numbers[] = line.split(" ");

                while (col < gp.maxScreenCol) {
                    int num = Integer.parseInt(numbers[col]);
                    mapTileNum[col][row] = num;
                    col++;
                }
                if (col == gp.maxScreenCol) {
                    col = 0;
                    row++;
                }
            }
            br.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void draw(Graphics2D g2) {
        int col = 0;
        int row = 0;
        int x = 0;
        int y = 0;

        while (col < gp.maxScreenCol && row < gp.maxScreenRow) {
            int tileNum = mapTileNum[col][row];

            // Assign colors based on numbers in the text file
            if (tileNum == 0) {
                g2.setColor(new Color(133, 167, 124)); // Soft Grass Green
            } else if (tileNum == 1) {
                g2.setColor(new Color(92, 114, 85));   // Dark Green Border/Fence
            } else if (tileNum == 2) {
                g2.setColor(new Color(210, 180, 140));  // Sandy/Dirt Path
            }

            g2.fillRect(x, y, gp.tileSize, gp.tileSize);
            col++;
            x += gp.tileSize;

            if (col == gp.maxScreenCol) {
                col = 0;
                x = 0;
                row++;
                y += gp.tileSize;
            }
        }
    }
}