using System.Collections;
using System.Collections.Generic;
using StateMachines;
using UnityEngine;

public class AntController : MonoBehaviour
{
    private Vector3 rectStartPosition;
    private List<Ant> selectedAnts;

    private void Awake()
    {
        // init list of selected ants 
        selectedAnts = new List<Ant>();
    }

    void Update()
    {
        if (Input.GetMouseButtonDown(0) && Camera.main != null)
        {
            // left mouse button press
            rectStartPosition = Camera.main.ScreenToWorldPoint(Input.mousePosition);

        }

        if (Input.GetMouseButtonUp(0) && Camera.main != null)
        {
            //left mouse button release
            Collider2D[] collider2DArray =
                Physics2D.OverlapAreaAll(rectStartPosition, Camera.main.ScreenToWorldPoint(Input.mousePosition));

            //remove selected ants
            foreach (Ant ant in selectedAnts)
            {
                ant.inRect = false;
            }

            selectedAnts.Clear();

            //select all ants in the area defined by the mouse click and drag
            foreach (Collider2D colidr2D in collider2DArray)
            {
                //specifies target is ant and not some other object with a rigid body
                Ant ant;
                ant = colidr2D.GetComponent<Ant>();
                if (ant != null)
                {
                    ant.inRect = true;
                    selectedAnts.Add(ant);
                }
            }

            //DEBUG
            Debug.Log("SelectedAnt count: " + selectedAnts.Count);

            
        }
        
        // right botton press
        if (Input.GetMouseButtonDown(1))
        {
            Vector3 moveToPositon = Camera.main.ScreenToWorldPoint(Input.mousePosition);

            foreach (Ant ant in selectedAnts)
            {
                ant.travelTarget = moveToPositon;
                ant.hasTarget = true;
            }
        }    
    }
}
