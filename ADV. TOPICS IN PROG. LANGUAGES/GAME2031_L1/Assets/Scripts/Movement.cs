using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Movement : MonoBehaviour
{
    public float movespeed = 5.0f;

    // Start is called before the first frame update
    void Start()
    {
        Debug.Log("GAME2031 - Lab 1 by Gastello Andrii");
    }

    // Update is called once per frame
    void Update()
    {
        Vector2 userInput = new Vector2(Input.GetAxis("Horizontal"), Input.GetAxis("Vertical"));

        transform.Translate(userInput * movespeed * Time.deltaTime);
    }
}
