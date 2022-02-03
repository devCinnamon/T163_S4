using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour
{
    public float movespeed = 5.0f;
    public float boundX = 3.25f;

    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        Vector2 userInput = new Vector2(Input.GetAxis("Horizontal"), 0);

        transform.Translate(userInput * movespeed * Time.deltaTime);

        // Movement Limitations
        if (transform.position.x >= boundX )
            transform.position = new Vector3(boundX, transform.position.y, transform.position.z);
        
        if (transform.position.x <= -boundX)
            transform.position = new Vector3(-boundX, transform.position.y, transform.position.z);
    }
}