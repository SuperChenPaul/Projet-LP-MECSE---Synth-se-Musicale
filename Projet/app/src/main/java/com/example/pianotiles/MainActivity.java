package com.example.pianotiles;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.media.MediaPlayer;
import android.net.Uri;
import android.os.Bundle;
import android.os.Handler;
import android.view.MotionEvent;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.Toast;
import android.widget.VideoView;

public class MainActivity extends AppCompatActivity {

    VideoView videoView;
    //int duration = Toast.LENGTH_SHORT;
    private MediaPlayer mediaPlayer1;

    @Override
    protected void onPostResume() {
        videoView.resume();
        super.onPostResume();
    }

    @Override
    protected void onRestart() {
        videoView.start();
        super.onRestart();
    }

    @SuppressLint("ClickableViewAccessibility")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        ImageView TouchePiano1 = findViewById(R.id.toucheP1);
        ImageView TouchePiano2 = findViewById(R.id.toucheP2);
        ImageView TouchePiano3 = findViewById(R.id.toucheP3);
        ImageView TouchePiano4 = findViewById(R.id.toucheP4);
        ImageView TouchePiano5 = findViewById(R.id.toucheP5);
        ImageView TouchePiano6 = findViewById(R.id.toucheP6);
        ImageView TouchePiano7 = findViewById(R.id.toucheP7);
        ImageView TouchePiano8 = findViewById(R.id.toucheP8);
        ImageView TouchePiano9 = findViewById(R.id.toucheP9);
        ImageView TouchePiano10 = findViewById(R.id.toucheP10);
        ImageView TouchePiano11 = findViewById(R.id.touchePN1);
        ImageView TouchePiano12 = findViewById(R.id.touchePN2);
        ImageView TouchePiano13 = findViewById(R.id.touchePN3);
        ImageView TouchePiano14 = findViewById(R.id.touchePN4);
        ImageView TouchePiano15 = findViewById(R.id.touchePN5);
        ImageView TouchePiano16 = findViewById(R.id.touchePN6);
        ImageView TouchePiano17 = findViewById(R.id.touchePN7);
        ImageView Touchemenu1 = findViewById(R.id.toucheMenu1);
        ImageView Touchemenu2 = findViewById(R.id.toucheMenu2);
        ImageView Touchemenu3 = findViewById(R.id.toucheMenu3);

        videoView = findViewById(R.id.backgroundwii);
        Uri uri = Uri.parse("android.resource://"+getPackageName()+"/"+R.raw.background);
        videoView.setVideoPath(String.valueOf(uri));
        videoView.start();

        mediaPlayer1 = MediaPlayer.create(this, R.raw.piano1);
        // Toast toast2 = Toast.makeText(this, "test2",duration);
        videoView.setOnPreparedListener(new MediaPlayer.OnPreparedListener() {
            @Override
            public void onPrepared(MediaPlayer mp) {

                mp.setLooping(true);
                mp.setVolume(0, 0);
            }
        });

        Touchemenu1.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View view, MotionEvent motionEvent) {
                return true;
            }
        });

        Touchemenu2.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View view, MotionEvent motionEvent) {
                return true;
            }
        });

        Touchemenu3.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View view, MotionEvent motionEvent) {
                return true;
            }
        });

        TouchePiano1.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {

                switch (event.getAction()) {
                    case MotionEvent.ACTION_DOWN:
                        // Case pour la touche quand appuyer
                        // Change l'image de la touche
                        mediaPlayer1.start();
                        TouchePiano1.setImageResource(R.drawable.touche_appuyer);
                        break;
                    case MotionEvent.ACTION_UP:
                        // Case pour la touche quand relacher
                        // Remet l'image de base de la touche
                        TouchePiano1.setImageResource(R.drawable.touche_base);
                        break;
                }
                return true;
            }
        });
        TouchePiano2.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                switch (event.getAction()) {
                    case MotionEvent.ACTION_DOWN:
                        // Case pour la touche quand appuyer
                        // Change l'image de la touche
                        mediaPlayer1.start();
                        TouchePiano2.setImageResource(R.drawable.touche_appuyer);
                        break;
                    case MotionEvent.ACTION_UP:
                        // Case pour la touche quand relacher
                        // Remet l'image de base de la touche
                        TouchePiano2.setImageResource(R.drawable.touche_base);
                        break;
                }
                    return true;
                }
        });

        TouchePiano3.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                switch (event.getAction()) {
                    case MotionEvent.ACTION_DOWN:
                        // Case pour la touche quand appuyer
                        // Change l'image de la touche
                        mediaPlayer1.start();
                        TouchePiano3.setImageResource(R.drawable.touche_appuyer);
                        break;
                    case MotionEvent.ACTION_UP:
                        // Case pour la touche quand relacher
                        // Remet l'image de base de la touche
                        TouchePiano3.setImageResource(R.drawable.touche_base);
                        break;
                }
                return true;
            }
        });
        TouchePiano4.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                switch (event.getAction()) {
                    case MotionEvent.ACTION_DOWN:
                        // Case pour la touche quand appuyer
                        // Change l'image de la touche
                        mediaPlayer1.start();
                        TouchePiano4.setImageResource(R.drawable.touche_appuyer);
                        break;
                    case MotionEvent.ACTION_UP:
                        // Case pour la touche quand relacher
                        // Remet l'image de base de la touche
                        TouchePiano4.setImageResource(R.drawable.touche_base);
                        break;
                }
                return true;
            }
        });
        TouchePiano5.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                switch (event.getAction()) {
                    case MotionEvent.ACTION_DOWN:
                        // Case pour la touche quand appuyer
                        // Change l'image de la touche noir
                        mediaPlayer1.start();
                        TouchePiano5.setImageResource(R.drawable.touche_appuyer);
                        break;
                    case MotionEvent.ACTION_UP:
                        // Case pour la touche quand relacher
                        // Remet l'image de base de la touche
                        TouchePiano5.setImageResource(R.drawable.touche_base);
                        break;
                }
                return true;
            }
        });
        TouchePiano6.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                switch (event.getAction()) {
                    case MotionEvent.ACTION_DOWN:
                        // Case pour la touche quand appuyer
                        // Change l'image de la touche
                        mediaPlayer1.start();
                        TouchePiano6.setImageResource(R.drawable.touche_appuyer);
                        break;
                    case MotionEvent.ACTION_UP:
                        // Case pour la touche quand relacher
                        // Remet l'image de base de la touche
                        TouchePiano6.setImageResource(R.drawable.touche_base);
                        break;
                }
                return true;
            }
        });
        TouchePiano7.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                switch (event.getAction()) {
                    case MotionEvent.ACTION_DOWN:
                        // Case pour la touche quand appuyer
                        // Change l'image de la touche noir
                        mediaPlayer1.start();
                        TouchePiano7.setImageResource(R.drawable.touche_appuyer);
                        break;
                    case MotionEvent.ACTION_UP:
                        // Case pour la touche quand relacher
                        // Remet l'image de base de la touche
                        TouchePiano7.setImageResource(R.drawable.touche_base);
                        break;
                }
                return true;
            }
        });
        TouchePiano8.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                switch (event.getAction()) {
                    case MotionEvent.ACTION_DOWN:
                        // Case pour la touche quand appuyer
                        // Change l'image de la touche
                        mediaPlayer1.start();
                        TouchePiano8.setImageResource(R.drawable.touche_appuyer);
                        break;
                    case MotionEvent.ACTION_UP:
                        // Case pour la touche quand relacher
                        // Remet l'image de base de la touche
                        TouchePiano8.setImageResource(R.drawable.touche_base);
                        break;
                }
                return true;
            }
        });
        TouchePiano9.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                switch (event.getAction()) {
                    case MotionEvent.ACTION_DOWN:
                        // Case pour la touche quand appuyer
                        // Change l'image de la touche noir
                        mediaPlayer1.start();
                        TouchePiano9.setImageResource(R.drawable.touche_appuyer);
                        break;
                    case MotionEvent.ACTION_UP:
                        // Case pour la touche quand relacher
                        // Remet l'image de base de la touche
                        TouchePiano9.setImageResource(R.drawable.touche_base);
                        break;
                }
                return true;
            }
        });
        TouchePiano10.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                switch (event.getAction()) {
                    case MotionEvent.ACTION_DOWN:
                        // Case pour la touche quand appuyer
                        // Change l'image de la touche
                        mediaPlayer1.start();
                        TouchePiano10.setImageResource(R.drawable.touche_appuyer);
                        break;
                    case MotionEvent.ACTION_UP:
                        // Case pour la touche quand relacher
                        // Remet l'image de base de la touche
                        TouchePiano10.setImageResource(R.drawable.touche_base);
                        break;
                }
                return true;
            }
        });
        TouchePiano11.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                switch (event.getAction()) {
                    case MotionEvent.ACTION_DOWN:
                        // Case pour la touche quand appuyer
                        // Change l'image de la touche noir
                        mediaPlayer1.start();
                        TouchePiano11.setImageResource(R.drawable.touche_noire_appuyer);
                        break;
                    case MotionEvent.ACTION_UP:
                        // Case pour la touche quand relacher
                        // Remet l'image de base de la touche noir
                        TouchePiano11.setImageResource(R.drawable.touche_noire3);
                        break;
                }
                return true;
            }
        });
        TouchePiano12.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                switch (event.getAction()) {
                    case MotionEvent.ACTION_DOWN:
                        // Case pour la touche quand appuyer
                        // Change l'image de la touche
                        mediaPlayer1.start();
                        TouchePiano12.setImageResource(R.drawable.touche_noire_appuyer);
                        break;
                    case MotionEvent.ACTION_UP:
                        // Case pour la touche quand relacher
                        // Remet l'image de base de la touche noir
                        TouchePiano12.setImageResource(R.drawable.touche_noire3);
                        break;
                }
                return true;
            }
        });
        TouchePiano13.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                switch (event.getAction()) {
                    case MotionEvent.ACTION_DOWN:
                        // Case pour la touche quand appuyer
                        // Change l'image de la touche
                        mediaPlayer1.start();
                        TouchePiano13.setImageResource(R.drawable.touche_noire_appuyer);
                        break;
                    case MotionEvent.ACTION_UP:
                        // Case pour la touche quand relacher
                        // Remet l'image de base de la touche noir
                        TouchePiano13.setImageResource(R.drawable.touche_noire3);
                        break;
                }
                return true;
            }
        });
        TouchePiano14.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                switch (event.getAction()) {
                    case MotionEvent.ACTION_DOWN:
                        // Case pour la touche quand appuyer
                        // Change l'image de la touche noir
                        mediaPlayer1.start();
                        TouchePiano14.setImageResource(R.drawable.touche_noire_appuyer);
                        break;
                    case MotionEvent.ACTION_UP:
                        // Case pour la touche quand relacher
                        // Remet l'image de base de la touche noir
                        TouchePiano14.setImageResource(R.drawable.touche_noire3);
                        break;
                }
                return true;
            }
        });
        TouchePiano15.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                switch (event.getAction()) {
                    case MotionEvent.ACTION_DOWN:
                        // Case pour la touche quand appuyer
                        // Change l'image de la touche
                        mediaPlayer1.start();
                        TouchePiano15.setImageResource(R.drawable.touche_noire_appuyer);
                        break;
                    case MotionEvent.ACTION_UP:
                        // Case pour la touche quand relacher
                        // Remet l'image de base de la touche noir
                        TouchePiano15.setImageResource(R.drawable.touche_noire3);
                        break;
                }
                return true;
            }
        });
        TouchePiano16.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                switch (event.getAction()) {
                    case MotionEvent.ACTION_DOWN:
                        // Case pour la touche quand appuyer
                        // Change l'image de la touche
                        mediaPlayer1.start();
                        TouchePiano16.setImageResource(R.drawable.touche_noire_appuyer);
                        break;
                    case MotionEvent.ACTION_UP:
                        // Case pour la touche quand relacher
                        // Remet l'image de base de la touche noir
                        TouchePiano16.setImageResource(R.drawable.touche_noire3);
                        break;
                }
                return true;
            }
        });
        TouchePiano17.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                switch (event.getAction()) {
                    case MotionEvent.ACTION_DOWN:
                        // Case pour la touche quand appuyer
                        // Change l'image de la touche noir
                        mediaPlayer1.start();
                        TouchePiano17.setImageResource(R.drawable.touche_noire_appuyer);
                        break;
                    case MotionEvent.ACTION_UP:
                        // Case pour la touche quand relacher
                        // Remet l'image de base de la touche noir
                        TouchePiano17.setImageResource(R.drawable.touche_noire3);
                        break;
                }
                return true;
            }
        });
    }
}
