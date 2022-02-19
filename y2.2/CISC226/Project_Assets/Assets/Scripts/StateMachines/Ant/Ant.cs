using UnityEngine;
using UnityEngine.Serialization;

namespace StateMachines 
{ 
    public class Ant : StateMachine
    {
        //states of ant
        public IdleAnt Idling;
        public MovingAnt Moving;
        public SelectedAnt Selected;
        
        // physics for ant
        public Rigidbody2D body;
        public bool hasTarget;
        public Vector3 travelTarget;
        public float speed = 4f;
        
        // selector fields
        public GameObject selectedSprite;
        public bool inRect;
        

        private void Awake()
        {
            body = GetComponent<Rigidbody2D>();
            selectedSprite = transform.Find("select").gameObject;
            
            Idling = new IdleAnt(this);
            Moving = new MovingAnt(this);
            Selected = new SelectedAnt(this);
        }

        protected override State GetInitialState()
        {
            return Idling;
        }

        /*
        protected override void OnGUI()
        {
            (float, float) inp = (Moving.Direction.x, Moving.Direction.y);
            GUILayout.Label($"<color='black><size=40>{inp}</size></color>");    
        }
        */
    }
}