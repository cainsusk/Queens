using UnityEngine;

namespace StateMachines
{
    public class KeyboardMovingAnt : State
    {
        private readonly Ant _ant;
        public Vector2 Direction;

        public KeyboardMovingAnt(StateMachine stateMachine) : base(stateMachine, "moving")
        {
            _ant = (Ant) stateMachine;
        }

        public override void Enter()
        {
            Direction = new Vector2(0, 0);
        }

        public override void UpdateLogic()
        {
            Direction = new Vector2(Input.GetAxis("Horizontal"), Input.GetAxis("Vertical"));
            
            if (Mathf.Abs(_ant.body.velocity.x) < Mathf.Epsilon && Mathf.Abs(_ant.body.velocity.y) < Mathf.Epsilon && Direction == Vector2.zero) 
            {
                stateMachine.IsNow(_ant.Idling);
            }
        }
        
        public override void UpdatePhysics()
        {
            _ant.body.velocity = new Vector2(Direction.x * _ant.speed, Direction.y * _ant.speed);
        }
    }
}
