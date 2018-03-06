function varargout = Control_Panel(varargin)
% CONTROL_PANEL MATLAB code for Control_Panel.fig
%      CONTROL_PANEL, by itself, creates a new CONTROL_PANEL or raises the existing
%      singleton*.
%
%      H = CONTROL_PANEL returns the handle to a new CONTROL_PANEL or the handle to
%      the existing singleton*.
%
%      CONTROL_PANEL('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in CONTROL_PANEL.M with the given input arguments.
%
%      CONTROL_PANEL('Property','Value',...) creates a new CONTROL_PANEL or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before Control_Panel_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to Control_Panel_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help Control_Panel

% Last Modified by GUIDE v2.5 13-Feb-2018 23:46:04

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @Control_Panel_OpeningFcn, ...
                   'gui_OutputFcn',  @Control_Panel_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before Control_Panel is made visible.
function Control_Panel_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to Control_Panel (see VARARGIN)

% teensy = serial('COM4');
% fopen(teensy);
% handles.teensy = teensy;

% Choose default command line output for Control_Panel
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes Control_Panel wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = Control_Panel_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in Start_button.
function Start_button_Callback(hObject, eventdata, handles)
% hObject    handle to Start_button (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Check checkbox
% Check connection to teensy
% Open solenoid valves
% Check pressure on other side of valve, close if not good
% Start logging data

confirm_start = handles.Start_radio;
if(confirm_start.Value == 1)
    teensy = handles.teensy;
    
    
    
end


% --- Executes on button press in Abort.
function Abort_Callback(hObject, eventdata, handles)
% hObject    handle to Abort (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Close solenoid valve
% Stop logging
