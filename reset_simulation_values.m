function varargout = reset_simulation_values(varargin)
global measuredTemp;
global coilCurrent;

% RESET_SIMULATION_VALUES MATLAB code for reset_simulation_values.fig
%      RESET_SIMULATION_VALUES, by itself, creates a new RESET_SIMULATION_VALUES or raises the existing
%      singleton*.
%
%      H = RESET_SIMULATION_VALUES returns the handle to a new RESET_SIMULATION_VALUES or the handle to
%      the existing singleton*.
%
%      RESET_SIMULATION_VALUES('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in RESET_SIMULATION_VALUES.M with the given input arguments.
%
%      RESET_SIMULATION_VALUES('Property','Value',...) creates a new RESET_SIMULATION_VALUES or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before reset_simulation_values_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to reset_simulation_values_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help reset_simulation_values

% Last Modified by GUIDE v2.5 02-Dec-2011 14:59:42

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @reset_simulation_values_OpeningFcn, ...
                   'gui_OutputFcn',  @reset_simulation_values_OutputFcn, ...
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


% --- Executes just before reset_simulation_values is made visible.
function reset_simulation_values_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to reset_simulation_values (see VARARGIN)

% Choose default command line output for reset_simulation_values
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes reset_simulation_values wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = reset_simulation_values_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global measuredTemp coilCurrent timeTick;
measuredTemp = 40;
coilCurrent = 10;
timeTick =0;
measuredTemp
coilCurrent
timeTick
