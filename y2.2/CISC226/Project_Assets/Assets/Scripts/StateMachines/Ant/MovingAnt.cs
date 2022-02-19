using UnityEngine;

namespace StateMachines
{
    public class MovingAnt : State 
    {
        private readonly Ant _ant;
        public Vector3 Direction;
        // arbitrary constant which dictates how close an ant will get to the moveTarget before stopping
        private const float MovePrecision = 1.005f;

        public MovingAnt(StateMachine stateMachine) : base(stateMachine, "moving")
        {
            _ant = (Ant) stateMachine;
        }

        public override void UpdateLogic()
        {
            if (Vector3.Distance(_ant.travelTarget, _ant.transform.position) < MovePrecision)
            {
                stateMachine.IsNow(_ant.Idling);
            } 
        }
        
        public override void UpdatePhysics()
        {
            Direction = (_ant.travelTarget - _ant.transform.position).normalized;
            _ant.body.velocity = Direction;
        }

        public override void Exit()
        {
            _ant.body.velocity = Vector2.zero;
            _ant.hasTarget = false;
        }
    }
}
