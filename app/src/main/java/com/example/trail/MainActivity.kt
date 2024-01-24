@file:OptIn(DelicateCoroutinesApi::class)

package com.example.trail

import android.os.Bundle
import android.util.Log
import android.view.View
import android.widget.Button
import android.widget.EditText
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity
import kotlinx.coroutines.DelicateCoroutinesApi
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.GlobalScope
import kotlinx.coroutines.launch
import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader

class MainActivity : AppCompatActivity() {

    private lateinit var ipEditText: EditText
    private lateinit var pingButton: Button
    private lateinit var resultTextView: TextView

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        ipEditText = findViewById(R.id.ipEditText)
        pingButton = findViewById(R.id.pingButton)
        resultTextView = findViewById(R.id.resultTextView)

        pingButton.setOnClickListener {
            val ipAddress = ipEditText.text.toString()
            GlobalScope.launch(Dispatchers.IO) {
                val result = performPing(ipAddress)
                launch(Dispatchers.Main) {
                    resultTextView.text = result
                }
            }
        }
    }

    private fun performPing(ipAddress: String): String {
        return try {
            Log.d("PingTest", "Performing ping for $ipAddress")
            val process = Runtime.getRuntime().exec("/system/bin/ping -c 1 $ipAddress")
            val reader = BufferedReader(InputStreamReader(process.inputStream))
            val response = StringBuilder()
            var line: String?
            while (reader.readLine().also { line = it } != null) {
                response.append(line).append("\n")
            }
            process.waitFor()
            response.toString()
        } catch (e: IOException) {
            e.printStackTrace()
            "Error: " + e.message
        } catch (e: InterruptedException) {
            e.printStackTrace()
            "Error: " + e.message
        }
    }
}