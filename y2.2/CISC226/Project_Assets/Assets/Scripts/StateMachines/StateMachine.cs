using UnityEngine;

namespace StateMachines
{
    public class StateMachine : MonoBehaviour
    {
        State CurrentState;

        void Start()
        {
            CurrentState = GetInitialState();
            if (CurrentState != null)
                CurrentState.Enter();
        }

        void Update()
        {
            if (CurrentState != null)
                CurrentState.UpdateLogic();
        }

        void LateUpdate()
        {
            if (CurrentState != null)
                CurrentState.UpdatePhysics();
        }

        public void IsNow(State newState)
        {
            CurrentState.Exit();

            CurrentState = newState;
            CurrentState.Enter();
            Debug.Log("TRANSITION");
        }

        protected virtual State GetInitialState()
        {
            return null;
        }
        
        protected virtual void OnGUI()
        {
            string content = CurrentState != null ? CurrentState.Name() : "(no current state)";
            (float, float) inp = (Input.GetAxis("Horizontal"), Input.GetAxis("Vertical"));
            GUILayout.Label($"<color='black><size=40>{content}</size></color>");
            GUILayout.Label($"<color='black><size=40>{inp}</size></color>");        
        }
    }
}