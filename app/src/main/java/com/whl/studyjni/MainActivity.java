package com.whl.studyjni;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import com.whl.studyjni.databinding.ActivityMainBinding;

import java.util.Arrays;

public class MainActivity extends AppCompatActivity {
    public static final String TAG = "whl**";

    // Used to load the 'studyjni' library on application startup.
    static {
        System.loadLibrary("studyjni");
    }

    private ActivityMainBinding binding;
    private int arr[] = {9, 3, 6, 7, 2, 3, 4, 5, 6, 1};

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // Example of a call to a native method
        TextView tv = binding.sampleText;
        tv.setText(stringFromJNI());

        tv.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
//                show();//调用 native 层的 show 方法,native 调用 java层的 show 方法
//                System.out.println(TAG + "2-1=" + delete(2, 1));
//                getNum();
//                getStaticNum();
//                getString();

//                System.out.println(TAG + "修改前a=" + a);
//                accessField();
//                System.out.println(TAG + "修改后a=" + a);

//                System.out.println(TAG + "从native层收到的:" + getName());
                System.out.println(TAG + "a数组排序前: " + Arrays.toString(arr));
                sortArr(arr);
                System.out.println(TAG + "a数组排序后: " + Arrays.toString(arr));

            }
        });
    }

    int a = 2;
    static int b = 1;
    String s = "whl";

    /**
     * A native method that is implemented by the 'studyjni' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public static native void show();

    public native int delete(int a, int b);

    public native void getNum();

    public native void getStaticNum();

    public native void getString();

    public native void accessField();

    //中文乱码问题
    public native String getName();

    //数组
    public native void sortArr(int[] a);


    public static void show(String msg) {
        System.out.println(TAG + "msg = " + msg);
    }

}