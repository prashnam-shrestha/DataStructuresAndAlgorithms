import javax.swing.JPanel;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;

public class GamePanel extends JPanel implements Runnable {

    // Screen Settings
    public final int originalTileSize = 16; 
    public final int scale = 3; 
    public final int tileSize = originalTileSize * scale; // 48x48 pixels
    
    public final int maxScreenCol = 16;
    public final int maxScreenRow = 12;
    public final int screenWidth = tileSize * maxScreenCol; // 768 pixels
    public final int screenHeight = tileSize * maxScreenRow; // 576 pixels

    // Game Core
    Thread gameThread;
    int FPS = 60;

    KeyHandler keyH = new KeyHandler();
    TileManager tileM = new TileManager(this); // Instantiate the Map Manager

    // Player default positions
    int playerX = 100;
    int playerY = 100;
    int playerSpeed = 4;

    public GamePanel() {
        this.setPreferredSize(new Dimension(screenWidth, screenHeight));
        this.setBackground(new Color(133, 167, 124)); // Sage green backup
        this.setDoubleBuffered(true);
        this.addKeyListener(keyH); 
        this.setFocusable(true);   
    }

    public void startGameThread() {
        gameThread = new Thread(this);
        gameThread.start();
    }

    @Override
    public void run() {
        double drawInterval = 1000000000 / FPS;
        double nextDrawTime = System.nanoTime() + drawInterval;

        while (gameThread != null) {
            update();
            repaint();

            try {
                double remainingTime = nextDrawTime - System.nanoTime();
                remainingTime = remainingTime / 1000000;

                if (remainingTime < 0) {
                    remainingTime = 0;
                }

                Thread.sleep((long) remainingTime);
                nextDrawTime += drawInterval;

            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public void update() {
        if (keyH.upPressed) { playerY -= playerSpeed; }
        if (keyH.downPressed) { playerY += playerSpeed; }
        if (keyH.leftPressed) { playerX -= playerSpeed; }
        if (keyH.rightPressed) { playerX += playerSpeed; }
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        Graphics2D g2 = (Graphics2D) g;

        // 1. DRAW MAP TILE GRID FIRST
        tileM.draw(g2);

        // 2. DRAW PLAYER BLOCK ON TOP
        g2.setColor(new Color(110, 68, 41)); // Warm brown
        g2.fillRect(playerX, playerY, tileSize, tileSize);

        g2.dispose();
    }
}